#ifndef ADDEDITCOMPUTERWIDGET_H
#define ADDEDITCOMPUTERWIDGET_H

#include <QWidget>
#include "idevicedetails.h"

namespace Ui {
class AddEditComputerWidget;
}

class AddEditComputerWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditComputerWidget(QWidget *parent = nullptr);
    ~AddEditComputerWidget();
    QString GetDeviceDescription() override;
private:
    Ui::AddEditComputerWidget *ui;
};

#endif // ADDEDITCOMPUTERWIDGET_H
