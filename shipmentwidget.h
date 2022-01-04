#ifndef SHIPMENTWIDGET_H
#define SHIPMENTWIDGET_H

#include <QWidget>
#include "currentuser.h"

namespace Ui {
class ShipmentWidget;
}

class ShipmentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShipmentWidget(QWidget *parent = nullptr);
    ~ShipmentWidget();
    void setShipmentInfo();

private:
    Ui::ShipmentWidget *ui;
};

#endif // SHIPMENTWIDGET_H
