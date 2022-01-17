#ifndef ADDNEWMOUSEWIDGET_H
#define ADDNEWMOUSEWIDGET_H

#include <QWidget>
#include "idevicedetails.h"

namespace Ui {
class AddNewMouseWidget;
}

class AddNewMouseWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddNewMouseWidget(QWidget *parent = nullptr);
    ~AddNewMouseWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddNewMouseWidget *ui;
};

#endif // ADDNEWMOUSEWIDGET_H
