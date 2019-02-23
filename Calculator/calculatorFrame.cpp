#include "calculatorFrame.h"
#include <QChar>
#include <stack>
#include <vector>
#include <unordered_map>
#include <utility>

using std::unordered_map;
using std::vector;
using std::pair;
using std::stack;

calculatorFrame::calculatorFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	set_initialized_state();
}

void calculatorFrame::set_initialized_state()
{
	ui.lineEdit->clear();
	current_expression.clear();

	ui.lcdNumber->display(0.0);
	current_operand = QString::number(0);
	corresponding_current_digit = 0.0;

	entered_non_zero_digit = false;
	entered_operator = false;
	entered_dot = false;
}

void calculatorFrame::on_zeroButton_clicked()
{
	if (!entered_dot && !entered_non_zero_digit)
	{
		//Neglect preceding 0s
		return;
	}
	else
	{
		current_operand.append(QString::number(0));
		corresponding_current_digit = current_operand.toDouble();
	}
	ui.lcdNumber->display(current_operand);
}

void calculatorFrame::nonzero_button_click(int which)
{
	if (equ(corresponding_current_digit, 0) && !entered_dot)
	{
		corresponding_current_digit = which;
		current_operand = QString::number(which);
		entered_non_zero_digit = true;
	}
	else
	{
		current_operand.append(QString::number(which));
		corresponding_current_digit = current_operand.toDouble();
	}
	entered_operator = false;
	ui.lcdNumber->display(current_operand);
}

void calculatorFrame::remove_postfix()
{
	//Remove preceding 0s in a decimal
	if (entered_dot)
	{
		while (current_operand[current_operand.length() - 1] == '0')
			current_operand.remove(current_operand.length() - 1, 1);
	}
	//If the last character is dot, remove it
	if (current_operand[current_operand.length() - 1] == '.')
	{
		current_operand.remove(current_operand.length() - 1, 1);
	}
	return;
}

void calculatorFrame::append_number()
{
	remove_postfix();

	//Deal with - neg(n) and + neg(n) cases
	if (current_operand[0] == '-' && !current_expression.isEmpty())
	{
		//Remove the neg sign in operand, then convert the original expression to fix it
		current_operand.remove(0, 1);
		if (current_expression[current_expression.length() - 1] == '+')
		{
			current_expression[current_expression.length() - 1] = '-';

		}
		else if (current_expression[current_expression.length() - 1] == '-')
		{
			current_expression[current_expression.length() - 1] = '+';
		}
		else // mul and div cases
		{
			//This function finds the position of last appeared + or - operator before the * / expression
			auto find_first_pm_operator = [&]()->int {
				int pos_index = current_expression.length() - 1;
				while (pos_index >= 0 && (current_expression[pos_index].isDigit() ||
					(current_expression[pos_index] == QChar(215) ||
						current_expression[pos_index] == QChar(247) ||
						current_expression[pos_index] == '.')))
					pos_index--;
				return pos_index;
			};
			int pos_index = find_first_pm_operator();


			//If the whole expression is concated with * and /
			if (pos_index == -1)
			{
				//The first number is already negative
				if (current_operand[0] == '-')
				{
					current_expression.remove(0, 1);
				}
				//No -0 appears
				else if (current_operand[0] == '0')
				{
					;
				}
				//non-0 number in the first position, add a neg sign
				else
				{
					current_expression.prepend('-');
				}

			}
			else //Find an changeable + or -
			{
				current_expression[pos_index] =
					(current_expression[pos_index] == '+' ? '-' : '+');
			}

		}
	}
	current_expression.append(current_operand);
}

//Change the negativity of current operand,
//and get ready for the next digit input
void calculatorFrame::operators_click(char ch)
{
	if (entered_operator)
	{
		//Neglect duplicate operator input
		return;
	}
	else
	{
		
		append_number();
		current_expression.append(QString(ch));

		//Use a more elegant form of * and / for displaying
		if (ch == '*')
		{
			current_expression.remove(current_expression.length() - 1, 1);
			current_expression.append(QApplication::translate("calculatorFrameClass", "\303\227", nullptr));
		}
		else if (ch == '/')
		{
			current_expression.remove(current_expression.length() - 1, 1);
			current_expression.append(QApplication::translate("calculatorFrameClass", "\303\267", nullptr));
		}
		entered_operator = true;
		on_CEButton_clicked();
	}
	ui.lcdNumber->display(current_operand);
	show_refined_expression();
}

//Eval result
void calculatorFrame::on_equalButton_clicked()
{
	//Append the current number into expression
	append_number();

	//Actual evaluation process
	struct expression_term
	{
		QChar operators;
		double number;
		bool is_operator;
	};
	unordered_map<char, int> support_operators({
		pair<char, int>('+', 1),
		pair<char, int>('-', 1),
		pair<char, int>(mul_char, 2),
		pair<char, int>(div_char, 2),
		});

	//Generate postfix expression
	vector<expression_term> postfix_expression;
	stack<QChar> assist_stack;
	for (int i = 0; i < current_expression.length(); i++)
	{
		//Digit term
		if (current_expression[i].isDigit())
		{
			int num_len = 1;
			//Consider number with dot
			while (i + num_len < current_expression.length() && 
				(current_expression[i + num_len].isDigit() || current_expression[i + num_len] == '.'))
				num_len++;
			//7 is dummy number, change it freely
			postfix_expression.push_back({ QChar(7), current_expression.mid(i, num_len).toDouble(), false });
			i += (num_len - 1);
		}

		//Operators
		else
		{
			QChar current_operator = current_expression[i];
			if (assist_stack.empty() ||
				support_operators[assist_stack.top().toLatin1()] < support_operators[current_operator.toLatin1()])
			{
				assist_stack.push(current_operator);
			}
			else
			{
				while (!assist_stack.empty() &&
					(support_operators[assist_stack.top().toLatin1()] >= support_operators[current_operator.toLatin1()]))
				{

					postfix_expression.push_back({ assist_stack.top(), -1, true });
					assist_stack.pop();
				}

			}
		}
	}
	//Let out the rest operators
	while (!assist_stack.empty())
	{
		postfix_expression.push_back({ assist_stack.top(), -1, true });
		assist_stack.pop();
	}

	//Use postfix expression to evaluate value
	stack<double> st;
	for (const auto& elem : postfix_expression)
	{
		if (elem.is_operator)
		{
			//Note that operand2 is at front
			double operand2 = st.top();
			st.pop();
			double operand1 = st.top();
			st.pop();
			QChar current_operator = elem.operators;

			//QChar type is not suitable for enumeration, so use this if statement to imp
			if (current_operator == '+')
			{
				st.push(operand1 + operand2);
			}
			else if (current_operator == '-')
			{
				st.push(operand1 - operand2);
			}
			else if (current_operator == QChar(mul_char))
			{
				st.push(operand1 * operand2);
			}
			else
			{
				st.push(operand1 / operand2);
			}
		}
		else
		{
			st.push(elem.number);
		}
	}
	
	//One eval finished, get ready for the next eval
	set_initialized_state();
	ui.lcdNumber->display(st.top());
}

//Number status buttons
void calculatorFrame::on_symbolButton_clicked()
{
	if (less(0, corresponding_current_digit))
	{
		current_operand.prepend('-');
	}
	else if (less(corresponding_current_digit, 0))
	{
		current_operand.remove(0, 1);
	}
	else
	{
		//Ignore -0
		return;
	}
	corresponding_current_digit *= -1;
	ui.lcdNumber->display(corresponding_current_digit);
}

//Add dot to current operand
void calculatorFrame::on_dotButton_clicked()
{
	if (entered_dot)
	{
		//Neglect invalid input
		return;
	}
	else
	{
		current_operand.append('.');
		entered_dot = true;
	}
}

//Undo buttons
//Wipe entered expression and current digit
void calculatorFrame::on_CButton_clicked()
{
	set_initialized_state();
}

//Only wipe current decimal, expression remains
void calculatorFrame::on_CEButton_clicked()
{
	ui.lcdNumber->display(0.0);
	entered_dot = false;
	entered_non_zero_digit = false;
	corresponding_current_digit = 0.0;
}

//Only backspace one digit in current decimal
void calculatorFrame::on_backButton_clicked()
{
	//Only one digit or digit following by dot, like 3, 4., etc. 
	if (current_operand.size() == 1 || current_operand[current_operand.length() - 1] == '.')
	{
		current_operand = QString::number(0);
		corresponding_current_digit = 0;
		entered_non_zero_digit = false;
		entered_dot = false;
	}
	else
	{
		//If the character will be wiped is dot
		if (current_operand[current_operand.length() - 1] == '.')
		{
			entered_dot = false;
		}

		current_operand.remove(current_operand.length() - 1, 1);
		if (current_operand[current_operand.length() - 1] == '.')
		{
			corresponding_current_digit = QString(current_operand + '0').toDouble();
		}
		else
		{
			corresponding_current_digit = current_operand.toDouble();
		}
	}
	ui.lcdNumber->display(corresponding_current_digit);
}

void calculatorFrame::show_refined_expression()
{
	QString displayed_expression;
	auto should_insert_space = [&](const QChar ch1, const QChar ch2)->bool {
		return (ch1.isDigit() && !ch2.isDigit()) ||
		(!ch1.isDigit() && ch2.isDigit());
	};
	for (int i = 0; i < current_expression.length(); i++)
	{
		displayed_expression.append(current_expression[i]);
		if (i + 1 < current_expression.length() && 
			should_insert_space(current_expression[i], current_expression[i + 1]))
		{
			displayed_expression.append(' ');
		}
	}
	ui.lineEdit->setText(displayed_expression);
	ui.lineEdit->show();
}