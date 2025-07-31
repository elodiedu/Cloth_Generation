#pragma once

#include <QObject>

class Runner : public QObject
{
    Q_OBJECT
public:
    explicit Runner(QObject* parent = nullptr);

public slots:
    void showWindow();
};


// Runner.cpp
#include "Runner.h"
#include "Qt_file/mainwindow.h"
#include <QApplication>

Runner::Runner(QObject* parent)
    : QObject(parent)
{
}

void Runner::showWindow()
{
    if (!QApplication::instance())
        return;

    MainWindow* window = new MainWindow();
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}