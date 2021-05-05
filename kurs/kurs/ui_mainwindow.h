/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Save;
    QAction *Save_as;
    QAction *Open;
    QAction *Create;
    QAction *Exit;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
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
    QGroupBox *groupBox2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *AddDoc;
    QRadioButton *AddRes;
    QRadioButton *AddAmb;
    QGroupBox *groupBox3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEditSerchFullName;
    QLineEdit *lineEditSerchSalaru;
    QLineEdit *lineEditSerchTelephone;
    QGroupBox *groupBox4;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *SerchFullNameRadio;
    QRadioButton *SerchSalaruRadio;
    QRadioButton *SerchTelephoneRadio;
    QGroupBox *groupBox5;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLineEdit *lineEditDeleteNomber;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEditfullname1_2;
    QLineEdit *lineEditcabinet1_2;
    QLineEdit *lineEditworkingtime1_2;
    QLineEdit *lineEditspecialyti1_2;
    QLineEdit *lineEdittelephone1_2;
    QLineEdit *lineEditsalaru1_2;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addButton;
    QPushButton *ShowTable;
    QPushButton *DeleteElement;
    QPushButton *SerchButton;
    QPushButton *ChangeButton;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_10;
    QPushButton *CancelButton;
    QPushButton *Aceppt;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 653);
        Save = new QAction(MainWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save_as = new QAction(MainWindow);
        Save_as->setObjectName(QString::fromUtf8("Save_as"));
        Open = new QAction(MainWindow);
        Open->setObjectName(QString::fromUtf8("Open"));
        Create = new QAction(MainWindow);
        Create->setObjectName(QString::fromUtf8("Create"));
        Exit = new QAction(MainWindow);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(9, 9, 800, 400));
        tableWidget->setMouseTracking(false);
        tableWidget->setTabletTracking(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(190, 410, 221, 191));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 21, 211, 166));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditfullname1 = new QLineEdit(layoutWidget);
        lineEditfullname1->setObjectName(QString::fromUtf8("lineEditfullname1"));

        verticalLayout_2->addWidget(lineEditfullname1);

        lineEditcabinet1 = new QLineEdit(layoutWidget);
        lineEditcabinet1->setObjectName(QString::fromUtf8("lineEditcabinet1"));

        verticalLayout_2->addWidget(lineEditcabinet1);

        lineEditworkingtime1 = new QLineEdit(layoutWidget);
        lineEditworkingtime1->setObjectName(QString::fromUtf8("lineEditworkingtime1"));

        verticalLayout_2->addWidget(lineEditworkingtime1);

        lineEditspecialyti1 = new QLineEdit(layoutWidget);
        lineEditspecialyti1->setObjectName(QString::fromUtf8("lineEditspecialyti1"));

        verticalLayout_2->addWidget(lineEditspecialyti1);

        lineEdittelephone1 = new QLineEdit(layoutWidget);
        lineEdittelephone1->setObjectName(QString::fromUtf8("lineEdittelephone1"));

        verticalLayout_2->addWidget(lineEdittelephone1);

        lineEditsalaru1 = new QLineEdit(layoutWidget);
        lineEditsalaru1->setObjectName(QString::fromUtf8("lineEditsalaru1"));

        verticalLayout_2->addWidget(lineEditsalaru1);


        horizontalLayout->addLayout(verticalLayout_2);

        groupBox2 = new QGroupBox(centralwidget);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setGeometry(QRect(190, 410, 201, 181));
        layoutWidget1 = new QWidget(groupBox2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 150, 71));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        AddDoc = new QRadioButton(layoutWidget1);
        AddDoc->setObjectName(QString::fromUtf8("AddDoc"));

        verticalLayout_4->addWidget(AddDoc);

        AddRes = new QRadioButton(layoutWidget1);
        AddRes->setObjectName(QString::fromUtf8("AddRes"));

        verticalLayout_4->addWidget(AddRes);

        AddAmb = new QRadioButton(layoutWidget1);
        AddAmb->setObjectName(QString::fromUtf8("AddAmb"));

        verticalLayout_4->addWidget(AddAmb);

        groupBox3 = new QGroupBox(centralwidget);
        groupBox3->setObjectName(QString::fromUtf8("groupBox3"));
        groupBox3->setGeometry(QRect(190, 410, 191, 111));
        layoutWidget2 = new QWidget(groupBox3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1, 21, 167, 82));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_5->addWidget(label_9);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEditSerchFullName = new QLineEdit(layoutWidget2);
        lineEditSerchFullName->setObjectName(QString::fromUtf8("lineEditSerchFullName"));

        verticalLayout_6->addWidget(lineEditSerchFullName);

        lineEditSerchSalaru = new QLineEdit(layoutWidget2);
        lineEditSerchSalaru->setObjectName(QString::fromUtf8("lineEditSerchSalaru"));

        verticalLayout_6->addWidget(lineEditSerchSalaru);

        lineEditSerchTelephone = new QLineEdit(layoutWidget2);
        lineEditSerchTelephone->setObjectName(QString::fromUtf8("lineEditSerchTelephone"));

        verticalLayout_6->addWidget(lineEditSerchTelephone);


        horizontalLayout_2->addLayout(verticalLayout_6);

        groupBox4 = new QGroupBox(centralwidget);
        groupBox4->setObjectName(QString::fromUtf8("groupBox4"));
        groupBox4->setGeometry(QRect(190, 410, 120, 101));
        layoutWidget3 = new QWidget(groupBox4);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 20, 86, 71));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        SerchFullNameRadio = new QRadioButton(layoutWidget3);
        SerchFullNameRadio->setObjectName(QString::fromUtf8("SerchFullNameRadio"));

        verticalLayout_7->addWidget(SerchFullNameRadio);

        SerchSalaruRadio = new QRadioButton(layoutWidget3);
        SerchSalaruRadio->setObjectName(QString::fromUtf8("SerchSalaruRadio"));

        verticalLayout_7->addWidget(SerchSalaruRadio);

        SerchTelephoneRadio = new QRadioButton(layoutWidget3);
        SerchTelephoneRadio->setObjectName(QString::fromUtf8("SerchTelephoneRadio"));

        verticalLayout_7->addWidget(SerchTelephoneRadio);

        groupBox5 = new QGroupBox(centralwidget);
        groupBox5->setObjectName(QString::fromUtf8("groupBox5"));
        groupBox5->setGeometry(QRect(190, 410, 221, 80));
        layoutWidget4 = new QWidget(groupBox5);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 30, 197, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        lineEditDeleteNomber = new QLineEdit(layoutWidget4);
        lineEditDeleteNomber->setObjectName(QString::fromUtf8("lineEditDeleteNomber"));

        horizontalLayout_3->addWidget(lineEditDeleteNomber);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(190, 410, 221, 191));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(1, 21, 211, 166));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_8->addWidget(label_11);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_8->addWidget(label_12);

        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_8->addWidget(label_13);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_8->addWidget(label_14);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_8->addWidget(label_15);

        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_8->addWidget(label_16);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lineEditfullname1_2 = new QLineEdit(layoutWidget_2);
        lineEditfullname1_2->setObjectName(QString::fromUtf8("lineEditfullname1_2"));

        verticalLayout_9->addWidget(lineEditfullname1_2);

        lineEditcabinet1_2 = new QLineEdit(layoutWidget_2);
        lineEditcabinet1_2->setObjectName(QString::fromUtf8("lineEditcabinet1_2"));

        verticalLayout_9->addWidget(lineEditcabinet1_2);

        lineEditworkingtime1_2 = new QLineEdit(layoutWidget_2);
        lineEditworkingtime1_2->setObjectName(QString::fromUtf8("lineEditworkingtime1_2"));

        verticalLayout_9->addWidget(lineEditworkingtime1_2);

        lineEditspecialyti1_2 = new QLineEdit(layoutWidget_2);
        lineEditspecialyti1_2->setObjectName(QString::fromUtf8("lineEditspecialyti1_2"));

        verticalLayout_9->addWidget(lineEditspecialyti1_2);

        lineEdittelephone1_2 = new QLineEdit(layoutWidget_2);
        lineEdittelephone1_2->setObjectName(QString::fromUtf8("lineEdittelephone1_2"));

        verticalLayout_9->addWidget(lineEdittelephone1_2);

        lineEditsalaru1_2 = new QLineEdit(layoutWidget_2);
        lineEditsalaru1_2->setObjectName(QString::fromUtf8("lineEditsalaru1_2"));

        verticalLayout_9->addWidget(lineEditsalaru1_2);


        horizontalLayout_4->addLayout(verticalLayout_9);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(11, 421, 161, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(layoutWidget5);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_3->addWidget(addButton);

        ShowTable = new QPushButton(layoutWidget5);
        ShowTable->setObjectName(QString::fromUtf8("ShowTable"));

        verticalLayout_3->addWidget(ShowTable);

        DeleteElement = new QPushButton(layoutWidget5);
        DeleteElement->setObjectName(QString::fromUtf8("DeleteElement"));

        verticalLayout_3->addWidget(DeleteElement);

        SerchButton = new QPushButton(layoutWidget5);
        SerchButton->setObjectName(QString::fromUtf8("SerchButton"));

        verticalLayout_3->addWidget(SerchButton);

        ChangeButton = new QPushButton(layoutWidget5);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));

        verticalLayout_3->addWidget(ChangeButton);

        layoutWidget6 = new QWidget(centralwidget);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(11, 556, 161, 50));
        verticalLayout_10 = new QVBoxLayout(layoutWidget6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        CancelButton = new QPushButton(layoutWidget6);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        verticalLayout_10->addWidget(CancelButton);

        Aceppt = new QPushButton(layoutWidget6);
        Aceppt->setObjectName(QString::fromUtf8("Aceppt"));

        verticalLayout_10->addWidget(Aceppt);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Save);
        menu->addAction(Save_as);
        menu->addAction(Open);
        menu->addAction(Create);
        menu->addAction(Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        Save_as->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        Open->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        Create->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244.\320\230.\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\261\320\270\320\265\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\261\320\276\321\207\320\265\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\321\200\320\277\320\273\320\260\321\202\320\260", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        AddDoc->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\272\321\202\320\276\321\200", nullptr));
        AddRes->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\275\320\270\320\272 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\202\321\203\321\200\321\213", nullptr));
        AddAmb->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214 \321\201\320\272\320\276\321\200\320\276\320\271", nullptr));
        groupBox3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\321\200\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        groupBox4->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        SerchFullNameRadio->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        SerchSalaruRadio->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\277\320\273\320\260\321\202\320\260", nullptr));
        SerchTelephoneRadio->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        groupBox5->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\244.\320\230.\320\236", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\261\320\270\320\265\321\202", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\321\200\320\260\320\261\320\276\321\207\320\265\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\321\200\320\277\320\273\320\260\321\202\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        ShowTable->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        DeleteElement->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        SerchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        ChangeButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        CancelButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        Aceppt->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
