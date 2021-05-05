#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ShowTable_clicked();
    void on_addButton_clicked();
    void on_Aceppt_clicked();
    void on_DeleteElement_clicked();
    void on_SerchButton_clicked();
    void on_ChangeButton_clicked();
    void on_CancelButton_clicked();
    void on_Save_triggered();
    void on_Open_triggered();
    void on_Save_as_triggered();
    void on_Create_triggered();
    void on_Exit_triggered();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
