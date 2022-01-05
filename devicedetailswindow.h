#ifndef DEVICEDETAILSWINDOW_H
#define DEVICEDETAILSWINDOW_H

#include <QDialog>
#include "device.h"

namespace Ui {
class DeviceDetailsWindow;
}

class DeviceDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceDetailsWindow(Device, QWidget *parent = nullptr);
    ~DeviceDetailsWindow();

private:
    Device m_device;
    Ui::DeviceDetailsWindow *ui;
    void setControls();
};

#endif // DEVICEDETAILSWINDOW_H
