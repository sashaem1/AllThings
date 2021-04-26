/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditfullname1;
    QLineEdit *lineEditcabinet1;
    QLineEdit *lineEditworkingtime1;
    QLineEdit *lineEditspecialyti1;
    QLineEdit *lineEdittelephone1;
    QLineEdit *lineEditsalaru1;
    QPushButton *Aceppt;
    QPushButton *ShowTable;
    QPushButton *addButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 639);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(9, 9, 800, 400));
        tableWidget->setMouseTracking(false);
        tableWidget->setTabletTracking(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(190, 410, 201, 191));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 21, 191, 166));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditfullname1 = new QLineEdit(widget);
        lineEditfullname1->setObjectName(QString::fromUtf8("lineEditfullname1"));

        verticalLayout_2->addWidget(lineEditfullname1);

        lineEditcabinet1 = new QLineEdit(widget);
        lineEditcabinet1->setObjectName(QString::fromUtf8("lineEditcabinet1"));

        verticalLayout_2->addWidget(lineEditcabinet1);

        lineEditworkingtime1 = new QLineEdit(widget);
        lineEditworkingtime1->setObjectName(QString::fromUtf8("lineEditworkingtime1"));

        verticalLayout_2->addWidget(lineEditworkingtime1);

        lineEditspecialyti1 = new QLineEdit(widget);
        lineEditspecialyti1->setObjectName(QString::fromUtf8("lineEditspecialyti1"));

        verticalLayout_2->addWidget(lineEditspecialyti1);

        lineEdittelephone1 = new QLineEdit(widget);
        lineEdittelephone1->setObjectName(QString::fromUtf8("lineEdittelephone1"));

        verticalLayout_2->addWidget(lineEdittelephone1);

        lineEditsalaru1 = new QLineEdit(widget);
        lineEditsalaru1->setObjectName(QString::fromUtf8("lineEditsalaru1"));

        verticalLayout_2->addWidget(lineEditsalaru1);


        horizontalLayout->addLayout(verticalLayout_2);

        Aceppt = new QPushButton(centralwidget);
        Aceppt->setObjectName(QString::fromUtf8("Aceppt"));
        Aceppt->setGeometry(QRect(10, 570, 151, 21));
        ShowTable = new QPushButton(centralwidget);
        ShowTable->setObjectName(QString::fromUtf8("ShowTable"));
        ShowTable->setGeometry(QRect(11, 468, 151, 21));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(11, 441, 151, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244.\320\230.\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\261\320\270\320\265\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\261\320\276\321\207\320\265\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\321\200\320\277\320\273\320\260\321\202\320\260", nullptr));
        Aceppt->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        ShowTable->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
