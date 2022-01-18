#ifndef MANAGERDEVICEWIDGET_H
#define MANAGERDEVICEWIDGET_H

#include <QWidget>
#include "device.h"
#include "devicetype.h"
#include "addeditdevicewindow.h"

namespace Ui {
class ManagerDeviceWidget;
}

class ManagerDeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerDeviceWidget(Device*, QWidget *parent = nullptr);
    ~ManagerDeviceWidget();

private slots:
    void on_btnEdit_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ManagerDeviceWidget *ui;
    Device* m_device = nullptr;
    void setControls();
};

#endif // MANAGERDEVICEWIDGET_H
