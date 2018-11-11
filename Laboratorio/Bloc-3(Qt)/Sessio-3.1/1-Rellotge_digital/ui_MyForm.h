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
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber_3;
    QDial *dial_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QDial *dial_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(585, 363);
        MyForm->setMinimumSize(QSize(0, 0));
        verticalLayout_6 = new QVBoxLayout(MyForm);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 90, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        lcdNumber_3 = new QLCDNumber(MyForm);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setMinimumSize(QSize(80, 80));

        verticalLayout_2->addWidget(lcdNumber_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        dial_3 = new QDial(MyForm);
        dial_3->setObjectName(QStringLiteral("dial_3"));
        dial_3->setMinimumSize(QSize(60, 60));
        dial_3->setBaseSize(QSize(60, 60));
        dial_3->setMaximum(23);

        verticalLayout_3->addWidget(dial_3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(MyForm);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setMinimumSize(QSize(80, 80));

        verticalLayout->addWidget(lcdNumber_2);


        verticalLayout_4->addLayout(verticalLayout);

        dial_2 = new QDial(MyForm);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setMinimumSize(QSize(60, 60));
        dial_2->setBaseSize(QSize(60, 60));
        dial_2->setMaximum(59);

        verticalLayout_4->addWidget(dial_2);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);


        retranslateUi(MyForm);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(dial_3, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0));
        label->setText(QApplication::translate("MyForm", "Hours", 0));
        label_2->setText(QApplication::translate("MyForm", "Minutes", 0));
        pushButton_2->setText(QApplication::translate("MyForm", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
