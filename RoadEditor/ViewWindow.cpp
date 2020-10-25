#include "ViewWindow.h"
#include "ui_ViewWindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
}

ViewWindow::~ViewWindow()
{
    delete ui;
}

OpenGlWidget * ViewWindow::openGlWidget()
{
    return ui->openGLWidget;
}


