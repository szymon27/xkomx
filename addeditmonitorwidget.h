#ifndef ADDEDITMONITORWIDGET_H
#define ADDEDITMONITORWIDGET_H

#include <QWidget>
#include "displaytype.h"
#include "monitor.h"
#include "idevicedetails.h"
#include "QMessageBox"
namespace Ui {
class AddEditMonitorWidget;
}

class AddEditMonitorWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditMonitorWidget(QWidget *parent = nullptr);
    explicit AddEditMonitorWidget(class::Monitor* device, QWidget *parent = nullptr);
    ~AddEditMonitorWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddEditMonitorWidget *ui;
    void fillCombo();
};

#endif // ADDEDITMONITORWIDGET_H
