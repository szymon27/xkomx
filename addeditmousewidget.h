#ifndef ADDEDITMOUSEWIDGET_H
#define ADDEDITMOUSEWIDGET_H

#include <QWidget>
#include "mouse.h"
#include "idevicedetails.h"

namespace Ui {
class AddEditMouseWidget;
}

class AddEditMouseWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditMouseWidget(QWidget *parent = nullptr);
    explicit AddEditMouseWidget(class::Mouse* device, QWidget *parent = nullptr);
    ~AddEditMouseWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddEditMouseWidget *ui;
};

#endif // ADDEDITMOUSEWIDGET_H
