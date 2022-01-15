#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QWidget>
#include "DbManager.h"
#include "cartdevicewidget.h"
#include "cart.h"
#include "orderdetailswindow.h"

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
private slots:
    void on_btnBuy_clicked();

private:
    Ui::CartWidget *ui;
};

#endif // CARTWIDGET_H
