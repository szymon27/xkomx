#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>
#include "device.h"
#include "devicetype.h"

namespace Ui {
class DeviceWidget;
}

class DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceWidget(QWidget *parent = nullptr);
    ~DeviceWidget();
    void setDevice(Device device);

private:
    Ui::DeviceWidget *ui;
};

#endif // DEVICEWIDGET_H
