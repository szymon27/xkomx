#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>
#include "device.h"
#include "devicetype.h"
#include "devicedetailswindow.h"

namespace Ui {
class DeviceWidget;
}

class DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceWidget(Device* device, QWidget *parent = nullptr);
    ~DeviceWidget();
    void setDevice(Device* device);
    Device* device(){return m_device;}

private slots:
    void on_btnDetails_clicked();

private:
    Device* m_device = nullptr;
    void setControls();
    Ui::DeviceWidget *ui;
};

#endif // DEVICEWIDGET_H
