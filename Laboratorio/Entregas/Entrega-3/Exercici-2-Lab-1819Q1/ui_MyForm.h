/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyLCDNumber.h"

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    MyLCDNumber *lcdNumber;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(403, 285);
        verticalLayout_7 = new QVBoxLayout(MyForm);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_4->addWidget(spinBox);

        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        spinBox_2 = new QSpinBox(MyForm);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_4->addWidget(spinBox_2);

        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        lcdNumber = new MyLCDNumber(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_4->addWidget(lcdNumber);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(MyForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(MyForm);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(MyForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        checkBox = new QCheckBox(MyForm);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_5->addWidget(checkBox);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_6 = new QPushButton(MyForm);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(MyForm);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgba(127, 127, 127, 200);"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_7->addLayout(horizontalLayout);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber, SLOT(suma()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), lcdNumber, SLOT(reset()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), lcdNumber, SLOT(resta()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), lcdNumber, SLOT(multiplicacio()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), lcdNumber, SLOT(divisio()));
        QObject::connect(checkBox, SIGNAL(clicked()), lcdNumber, SLOT(canviarValorAbsolut()));
        QObject::connect(lcdNumber, SIGNAL(desactivarValorAbsolut()), checkBox, SLOT(animateClick()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), lcdNumber, SLOT(acumular()));
        QObject::connect(lcdNumber, SIGNAL(evniarInfoError(QString)), label_4, SLOT(setText(QString)));
        QObject::connect(lcdNumber, SIGNAL(enviarEstilError(QString)), label_4, SLOT(setStyleSheet(QString)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber, SLOT(assignarOp1(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), lcdNumber, SLOT(assignarOp2(int)));
        QObject::connect(lcdNumber, SIGNAL(valorPerDefecte(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(lcdNumber, SIGNAL(valorPerDefecte(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(lcdNumber, SIGNAL(enviarAOp1(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Calculadora", 0));
        label_2->setText(QApplication::translate("MyForm", "op", 0));
        label_3->setText(QApplication::translate("MyForm", "=", 0));
        label_4->setText(QString());
        label->setText(QApplication::translate("MyForm", "Operacions (op):", 0));
        pushButton_2->setText(QApplication::translate("MyForm", "+", 0));
        pushButton_3->setText(QApplication::translate("MyForm", "-", 0));
        pushButton_5->setText(QApplication::translate("MyForm", "*", 0));
        pushButton_4->setText(QApplication::translate("MyForm", "/", 0));
        checkBox->setText(QApplication::translate("MyForm", "Valor absolut", 0));
        pushButton_6->setText(QApplication::translate("MyForm", "Acumula", 0));
        pushButton_7->setText(QApplication::translate("MyForm", "Reset", 0));
        pushButton->setText(QApplication::translate("MyForm", "Sortir", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
