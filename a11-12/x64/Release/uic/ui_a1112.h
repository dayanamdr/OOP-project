/********************************************************************************
** Form generated from reading UI file 'a1112.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A1112_H
#define UI_A1112_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_a1112Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *a1112Class)
    {
        if (a1112Class->objectName().isEmpty())
            a1112Class->setObjectName(QString::fromUtf8("a1112Class"));
        a1112Class->resize(600, 400);
        menuBar = new QMenuBar(a1112Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        a1112Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(a1112Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        a1112Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(a1112Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        a1112Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(a1112Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        a1112Class->setStatusBar(statusBar);

        retranslateUi(a1112Class);

        QMetaObject::connectSlotsByName(a1112Class);
    } // setupUi

    void retranslateUi(QMainWindow *a1112Class)
    {
        a1112Class->setWindowTitle(QCoreApplication::translate("a1112Class", "a1112", nullptr));
    } // retranslateUi

};

namespace Ui {
    class a1112Class: public Ui_a1112Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A1112_H
