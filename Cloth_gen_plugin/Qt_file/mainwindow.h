#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QDialog>
#include <QWidget>
#include <QObject>
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
   MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
	void on_pushButton_clicked();
    void on_DeleteButton_clicked();
    Ui::MainWindow* ui;
    int combo_idx = 0;



private:
    void change_type(int index);
    void on_btnSelectImage_clicked();
    void on_helpButton_clicked();
};
#endif // MAINWINDOW_H
