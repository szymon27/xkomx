#ifndef CARTDEVICEWIDGET_H
#define CARTDEVICEWIDGET_H

#include <QWidget>
#include <cart.h>
namespace Ui {
class CartDeviceWidget;
}

class CartDeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CartDeviceWidget(CartElement cartElement, QWidget *parent = nullptr);
    ~CartDeviceWidget();
signals:
    void update();
    void changePrice();
private slots:
    void on_sbxQuantity_valueChanged(int count);

    void on_pushButton_clicked();

private:
    Ui::CartDeviceWidget *ui;
    CartElement m_cartElement;
};

#endif // CARTDEVICEWIDGET_H
