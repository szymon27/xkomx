#ifndef ADDNEWCOMPUTERWIDGET_H
#define ADDNEWCOMPUTERWIDGET_H

#include <QWidget>
#include "idevicedetails.h"

namespace Ui {
class AddNewComputerWidget;
}

class AddNewComputerWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddNewComputerWidget(QWidget *parent = nullptr);
    ~AddNewComputerWidget();
    QString GetDeviceDescription() override;
private:
    Ui::AddNewComputerWidget *ui;
};

#endif // ADDNEWCOMPUTERWIDGET_H
