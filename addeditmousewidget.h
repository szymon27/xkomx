#ifndef ADDEDITMOUSEWIDGET_H
#define ADDEDITMOUSEWIDGET_H

#include <QWidget>
#include "idevicedetails.h"

namespace Ui {
class AddEditMouseWidget;
}

class AddEditMouseWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditMouseWidget(QWidget *parent = nullptr);
    ~AddEditMouseWidget();
    QString GetDeviceDescription() override;

private:
    Ui::AddEditMouseWidget *ui;
};

#endif // ADDEDITMOUSEWIDGET_H
