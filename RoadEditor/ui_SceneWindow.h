/********************************************************************************
** Form generated from reading UI file 'SceneWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEWINDOW_H
#define UI_SCENEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;

    void setupUi(QWidget *SceneWindow)
    {
        if (SceneWindow->objectName().isEmpty())
            SceneWindow->setObjectName(QString::fromUtf8("SceneWindow"));
        SceneWindow->resize(400, 300);
        SceneWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        verticalLayout = new QVBoxLayout(SceneWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(SceneWindow);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);


        retranslateUi(SceneWindow);

        QMetaObject::connectSlotsByName(SceneWindow);
    } // setupUi

    void retranslateUi(QWidget *SceneWindow)
    {
        SceneWindow->setWindowTitle(QCoreApplication::translate("SceneWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SceneWindow: public Ui_SceneWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEWINDOW_H
