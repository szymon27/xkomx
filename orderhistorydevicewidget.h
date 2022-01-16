#ifndef ORDERHISTORYDEVICEWIDGET_H
#define ORDERHISTORYDEVICEWIDGET_H

#include <QWidget>
#include "device.h"
#include "order.h"

namespace Ui {
class OrderHistoryDeviceWidget;
}

class OrderHistoryDeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderHistoryDeviceWidget(OrderDetails orderDetails, QWidget *parent = nullptr);
    ~OrderHistoryDeviceWidget();

private:
    Ui::OrderHistoryDeviceWidget *ui;
};

#endif // ORDERHISTORYDEVICEWIDGET_H
