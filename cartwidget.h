#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QWidget>
#include "DbManager.h"
#include "cartdevicewidget.h"

namespace Ui {
class CartWidget;
}

class CartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CartWidget(QWidget *parent = nullptr);
    ~CartWidget();
    void setUpWidget();
private:
    Ui::CartWidget *ui;
};

#endif // CARTWIDGET_H
