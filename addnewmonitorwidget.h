#ifndef ADDNEWMONITORWIDGET_H
#define ADDNEWMONITORWIDGET_H

#include <QWidget>
#include "displaytype.h"
#include "idevicedetails.h"

namespace Ui {
class AddNewMonitorWidget;
}

class AddNewMonitorWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddNewMonitorWidget(QWidget *parent = nullptr);
    ~AddNewMonitorWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddNewMonitorWidget *ui;
    void fillCombo();
};

#endif // ADDNEWMONITORWIDGET_H
