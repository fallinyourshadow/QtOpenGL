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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <SourceTreeView.h>

QT_BEGIN_NAMESPACE

class Ui_SceneWindow
{
public:
    QVBoxLayout *vboxLayout;
    SourceTreeView *treeView;

    void setupUi(QWidget *SceneWindow)
    {
        if (SceneWindow->objectName().isEmpty())
            SceneWindow->setObjectName(QString::fromUtf8("SceneWindow"));
        SceneWindow->resize(331, 645);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SceneWindow->sizePolicy().hasHeightForWidth());
        SceneWindow->setSizePolicy(sizePolicy);
        SceneWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        vboxLayout = new QVBoxLayout(SceneWindow);
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new SourceTreeView(SceneWindow);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);

        vboxLayout->addWidget(treeView);


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
