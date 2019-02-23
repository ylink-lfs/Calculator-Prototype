/********************************************************************************
** Form generated from reading UI file 'calculatorFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORFRAME_H
#define UI_CALCULATORFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculatorFrameClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLCDNumber *lcdNumber;
    QGridLayout *gridLayout;
    QPushButton *CButton;
    QPushButton *CEButton;
    QPushButton *backButton;
    QPushButton *symbolButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *divButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *multButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *subButton;
    QPushButton *dotButton;
    QPushButton *zeroButton;
    QPushButton *equalButton;
    QPushButton *plusButton;

    void setupUi(QWidget *calculatorFrameClass)
    {
        if (calculatorFrameClass->objectName().isEmpty())
            calculatorFrameClass->setObjectName(QStringLiteral("calculatorFrameClass"));
        calculatorFrameClass->resize(592, 422);
        layoutWidget = new QWidget(calculatorFrameClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 571, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(10);

        verticalLayout->addWidget(lcdNumber);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CButton = new QPushButton(layoutWidget);
        CButton->setObjectName(QStringLiteral("CButton"));

        gridLayout->addWidget(CButton, 0, 0, 1, 1);

        CEButton = new QPushButton(layoutWidget);
        CEButton->setObjectName(QStringLiteral("CEButton"));

        gridLayout->addWidget(CEButton, 0, 1, 1, 1);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QStringLiteral("backButton"));

        gridLayout->addWidget(backButton, 0, 2, 1, 1);

        symbolButton = new QPushButton(layoutWidget);
        symbolButton->setObjectName(QStringLiteral("symbolButton"));

        gridLayout->addWidget(symbolButton, 0, 3, 1, 1);

        sevenButton = new QPushButton(layoutWidget);
        sevenButton->setObjectName(QStringLiteral("sevenButton"));

        gridLayout->addWidget(sevenButton, 1, 0, 1, 1);

        eightButton = new QPushButton(layoutWidget);
        eightButton->setObjectName(QStringLiteral("eightButton"));

        gridLayout->addWidget(eightButton, 1, 1, 1, 1);

        nineButton = new QPushButton(layoutWidget);
        nineButton->setObjectName(QStringLiteral("nineButton"));

        gridLayout->addWidget(nineButton, 1, 2, 1, 1);

        divButton = new QPushButton(layoutWidget);
        divButton->setObjectName(QStringLiteral("divButton"));

        gridLayout->addWidget(divButton, 1, 3, 1, 1);

        fourButton = new QPushButton(layoutWidget);
        fourButton->setObjectName(QStringLiteral("fourButton"));

        gridLayout->addWidget(fourButton, 2, 0, 1, 1);

        fiveButton = new QPushButton(layoutWidget);
        fiveButton->setObjectName(QStringLiteral("fiveButton"));

        gridLayout->addWidget(fiveButton, 2, 1, 1, 1);

        sixButton = new QPushButton(layoutWidget);
        sixButton->setObjectName(QStringLiteral("sixButton"));

        gridLayout->addWidget(sixButton, 2, 2, 1, 1);

        multButton = new QPushButton(layoutWidget);
        multButton->setObjectName(QStringLiteral("multButton"));

        gridLayout->addWidget(multButton, 2, 3, 1, 1);

        oneButton = new QPushButton(layoutWidget);
        oneButton->setObjectName(QStringLiteral("oneButton"));

        gridLayout->addWidget(oneButton, 3, 0, 1, 1);

        twoButton = new QPushButton(layoutWidget);
        twoButton->setObjectName(QStringLiteral("twoButton"));

        gridLayout->addWidget(twoButton, 3, 1, 1, 1);

        threeButton = new QPushButton(layoutWidget);
        threeButton->setObjectName(QStringLiteral("threeButton"));

        gridLayout->addWidget(threeButton, 3, 2, 1, 1);

        subButton = new QPushButton(layoutWidget);
        subButton->setObjectName(QStringLiteral("subButton"));

        gridLayout->addWidget(subButton, 3, 3, 1, 1);

        dotButton = new QPushButton(layoutWidget);
        dotButton->setObjectName(QStringLiteral("dotButton"));

        gridLayout->addWidget(dotButton, 4, 0, 1, 1);

        zeroButton = new QPushButton(layoutWidget);
        zeroButton->setObjectName(QStringLiteral("zeroButton"));

        gridLayout->addWidget(zeroButton, 4, 1, 1, 1);

        equalButton = new QPushButton(layoutWidget);
        equalButton->setObjectName(QStringLiteral("equalButton"));

        gridLayout->addWidget(equalButton, 4, 2, 1, 1);

        plusButton = new QPushButton(layoutWidget);
        plusButton->setObjectName(QStringLiteral("plusButton"));

        gridLayout->addWidget(plusButton, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(calculatorFrameClass);

        QMetaObject::connectSlotsByName(calculatorFrameClass);
    } // setupUi

    void retranslateUi(QWidget *calculatorFrameClass)
    {
        calculatorFrameClass->setWindowTitle(QApplication::translate("calculatorFrameClass", "calculatorFrame", nullptr));
        CButton->setText(QApplication::translate("calculatorFrameClass", "C", nullptr));
        CEButton->setText(QApplication::translate("calculatorFrameClass", "CE", nullptr));
        backButton->setText(QApplication::translate("calculatorFrameClass", "<\342\200\224\342\200\224", nullptr));
        symbolButton->setText(QApplication::translate("calculatorFrameClass", "\302\261", nullptr));
        sevenButton->setText(QApplication::translate("calculatorFrameClass", "7", nullptr));
        eightButton->setText(QApplication::translate("calculatorFrameClass", "8", nullptr));
        nineButton->setText(QApplication::translate("calculatorFrameClass", "9", nullptr));
        divButton->setText(QApplication::translate("calculatorFrameClass", "\303\267", nullptr));
        fourButton->setText(QApplication::translate("calculatorFrameClass", "4", nullptr));
        fiveButton->setText(QApplication::translate("calculatorFrameClass", "5", nullptr));
        sixButton->setText(QApplication::translate("calculatorFrameClass", "6", nullptr));
        multButton->setText(QApplication::translate("calculatorFrameClass", "\303\227", nullptr));
        oneButton->setText(QApplication::translate("calculatorFrameClass", "1", nullptr));
        twoButton->setText(QApplication::translate("calculatorFrameClass", "2", nullptr));
        threeButton->setText(QApplication::translate("calculatorFrameClass", "3", nullptr));
        subButton->setText(QApplication::translate("calculatorFrameClass", "-", nullptr));
        dotButton->setText(QApplication::translate("calculatorFrameClass", "\342\200\242", nullptr));
        zeroButton->setText(QApplication::translate("calculatorFrameClass", "0", nullptr));
        equalButton->setText(QApplication::translate("calculatorFrameClass", "=", nullptr));
        plusButton->setText(QApplication::translate("calculatorFrameClass", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculatorFrameClass: public Ui_calculatorFrameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORFRAME_H
