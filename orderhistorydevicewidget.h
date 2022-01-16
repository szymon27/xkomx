#ifndef ORDERHISTORYDEVICEWIDGET_H
#define ORDERHISTORYDEVICEWIDGET_H

#include <QWidget>

namespace Ui {
class OrderHistoryDeviceWidget;
}

class OrderHistoryDeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderHistoryDeviceWidget(QWidget *parent = nullptr);
    ~OrderHistoryDeviceWidget();

private:
    Ui::OrderHistoryDeviceWidget *ui;
};

#endif // ORDERHISTORYDEVICEWIDGET_H
