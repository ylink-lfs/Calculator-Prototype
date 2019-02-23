#pragma once

#include <QtWidgets/QWidget>
#include <QString>
#include <cmath>
#include "ui_calculatorFrame.h"

using std::fabs;

class calculatorFrame : public QWidget
{
	Q_OBJECT

public:
	calculatorFrame(QWidget *parent = nullptr);

private:
	Ui::calculatorFrameClass ui;

	QString current_operand;
	QString current_expression;
	double corresponding_current_digit;

	bool entered_non_zero_digit;
	bool entered_operator;
	bool entered_dot;

	const double eps = 1e-10;
	bool equ(double x, double y) { return fabs(x - y) < eps; }
	bool less(double x, double y) { return x - y < -eps; }
	bool less_equ(double x, double y) { return x - y < eps; }

	const char mul_char = 215;
	const char div_char = 247;

	void nonzero_button_click(int which);
	void operators_click(char ch);	
	void show_refined_expression();
	void set_initialized_state();
	void remove_postfix();
	void append_number();
private slots:
	//Number buttons
	void on_zeroButton_clicked();
	void on_oneButton_clicked() { nonzero_button_click(1); }
	void on_twoButton_clicked() { nonzero_button_click(2); }
	void on_threeButton_clicked() { nonzero_button_click(3); }
	void on_fourButton_clicked() { nonzero_button_click(4); }
	void on_fiveButton_clicked() { nonzero_button_click(5); }
	void on_sixButton_clicked() { nonzero_button_click(6); }
	void on_sevenButton_clicked() { nonzero_button_click(7); }
	void on_eightButton_clicked() { nonzero_button_click(8); }
	void on_nineButton_clicked() { nonzero_button_click(9); }

	//Basic arithmetic buttons
	void on_plusButton_clicked() { operators_click('+'); }
	void on_subButton_clicked() { operators_click('-'); }
	void on_multButton_clicked() { operators_click('*'); }
	void on_divButton_clicked() { operators_click('/'); }
	void on_equalButton_clicked();

	//Number status buttons
	void on_symbolButton_clicked();
	void on_dotButton_clicked();

	//Undo buttons
	void on_CButton_clicked();
	void on_CEButton_clicked();
	void on_backButton_clicked();
};
