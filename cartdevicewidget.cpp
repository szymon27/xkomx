#include "cartdevicewidget.h"
#include "ui_cartdevicewidget.h"

CartDeviceWidget::CartDeviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CartDeviceWidget)
{
    ui->setupUi(this);
}

CartDeviceWidget::~CartDeviceWidget()
{
    delete ui;
}

void CartDeviceWidget::setCartDevice(Device device)
{
    ui->sbxQuantity->setValue(1); //zmiana na ilosc w koszyku z bazy
    ui->lbProducer->setText(device.m_producer);
    ui->lbModel->setText(device.m_model);
    ui->lbPrice->setText(QString::number(device.m_price));
    ui->lbImage->setPixmap(QPixmap::fromImage(device.m_image));
    ui->lbTotalPrice->setText(QString::number(device.m_price * 1)); // zmiana na sbxQuantity.getValue()
}
