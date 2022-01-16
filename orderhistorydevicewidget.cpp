#include "orderhistorydevicewidget.h"
#include "ui_orderhistorydevicewidget.h"

OrderHistoryDeviceWidget::OrderHistoryDeviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryDeviceWidget)
{
    ui->setupUi(this);
}

OrderHistoryDeviceWidget::~OrderHistoryDeviceWidget()
{
    delete ui;
}
