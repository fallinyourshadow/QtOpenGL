#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include "Topscene.h"
#include "OpenGlWidget.h"

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ViewWindow(QWidget *parent = nullptr);
    ~ViewWindow();
    OpenGlWidget * openGlWidget();

private:
    Ui::ViewWindow *ui;
};

#endif // VIEWWINDOW_H
