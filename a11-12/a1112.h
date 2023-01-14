#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a1112.h"

class a1112 : public QMainWindow
{
    Q_OBJECT

public:
    a1112(QWidget *parent = Q_NULLPTR);

private:
    Ui::a1112Class ui;
};


//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//
//#include <QMainWindow>
//
////QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
////QT_END_NAMESPACE
//
//class MainWindow : public QMainWindow
//{
//    Q_OBJECT
//
//public:
//    MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();
//
//private:
//    Ui::MainWindow* ui;
//};
//#endif // MAINWINDOW_H