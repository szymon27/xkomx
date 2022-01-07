#ifndef CARTDEVICEWIDGET_H
#define CARTDEVICEWIDGET_H

#include <QWidget>
#include <device.h>
namespace Ui {
class CartDeviceWidget;
}

class CartDeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CartDeviceWidget(QWidget *parent = nullptr);
    ~CartDeviceWidget();
    void setCartDevice(Device* device);

private:
    Ui::CartDeviceWidget *ui;
};

#endif // CARTDEVICEWIDGET_H
