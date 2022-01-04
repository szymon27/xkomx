#include "devicewidget.h"
#include "ui_devicewidget.h"

DeviceWidget::DeviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceWidget)
{
    ui->setupUi(this);
}

DeviceWidget::~DeviceWidget()
{
    delete ui;
}

void DeviceWidget::setDevice(Device device)
{
    ui->lbProducer->setText(device.m_producer);
    ui->lbModel->setText(device.m_model);
    ui->lbPrice->setText(QString::number(device.m_price));
    ui->lbImage->setPixmap(QPixmap::fromImage(device.m_image));
    ui->lbType->setText(deviceTypeToString(device.m_deviceType));
}
