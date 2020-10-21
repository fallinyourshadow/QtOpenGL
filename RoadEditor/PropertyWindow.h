#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QWidget>

namespace Ui {
class PropertyWindow;
}

class PropertyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWindow(QWidget *parent = nullptr);
    ~PropertyWindow();

private:
    Ui::PropertyWindow *ui;
};

#endif // PROPERTYWINDOW_H
