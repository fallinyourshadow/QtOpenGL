/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1231;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *Layout_left;
    QVBoxLayout *Layout_centre;
    QVBoxLayout *Layout_right;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(789, 619);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action1231 = new QAction(MainWindow);
        action1231->setObjectName(QString::fromUtf8("action1231"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        Layout_left = new QVBoxLayout();
        Layout_left->setSpacing(0);
        Layout_left->setObjectName(QString::fromUtf8("Layout_left"));
        Layout_left->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout_3->addLayout(Layout_left);

        Layout_centre = new QVBoxLayout();
        Layout_centre->setSpacing(0);
        Layout_centre->setObjectName(QString::fromUtf8("Layout_centre"));
        Layout_centre->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout_3->addLayout(Layout_centre);

        Layout_right = new QVBoxLayout();
        Layout_right->setSpacing(0);
        Layout_right->setObjectName(QString::fromUtf8("Layout_right"));
        Layout_right->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout_3->addLayout(Layout_right);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(0, 3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 789, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action1231->setText(QApplication::translate("MainWindow", "1231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
