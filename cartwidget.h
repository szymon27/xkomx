#ifndef CARTWIDGET_H
#define CARTWIDGET_H

#include <QWidget>
#include "dbmanager.h"
#include "cartdevicewidget.h"
#include "cart.h"
#include "orderdetailswindow.h"
#include "currentuser.h"
#include "signinwindow.h"
#include <QMessageBox>

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
    void update();
    void on_btnRemoveAll_clicked();
    void setPrice();
private:
    Ui::CartWidget *ui;
};

#endif // CARTWIDGET_H
