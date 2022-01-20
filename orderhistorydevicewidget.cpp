#include "orderhistorydevicewidget.h"
#include "ui_orderhistorydevicewidget.h"

OrderHistoryDeviceWidget::OrderHistoryDeviceWidget(OrderDetails od, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryDeviceWidget)
{
    ui->setupUi(this);
    ui->lbProducer->setText(od.producer);
    ui->lbModel->setText(od.model);
    ui->lbPrice->setText(QString::number(od.price,'f',2) + " PLN");
    ui->lbQuantity->setText(QString::number(od.count));
    ui->lbTotalCost->setText(QString::number(od.price * od.count,'f',2) + " PLN");
}

OrderHistoryDeviceWidget::~OrderHistoryDeviceWidget()
{
    delete ui;
}
