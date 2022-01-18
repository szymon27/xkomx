#ifndef ADDEDITMONITORWIDGET_H
#define ADDEDITMONITORWIDGET_H

#include <QWidget>
#include "displaytype.h"
#include "idevicedetails.h"

namespace Ui {
class AddEditMonitorWidget;
}

class AddEditMonitorWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditMonitorWidget(QWidget *parent = nullptr);
    ~AddEditMonitorWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddEditMonitorWidget *ui;
    void fillCombo();
};

#endif // ADDEDITMONITORWIDGET_H
