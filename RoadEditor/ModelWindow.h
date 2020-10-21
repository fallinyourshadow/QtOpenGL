#ifndef MODELWINDOW_H
#define MODELWINDOW_H

#include <QWidget>

namespace Ui {
class ModelWindow;
}

class ModelWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ModelWindow(QWidget *parent = nullptr);
    ~ModelWindow();

private:
    Ui::ModelWindow *ui;
};

#endif // MODELWINDOW_H
