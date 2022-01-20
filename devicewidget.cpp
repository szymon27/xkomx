#include "devicewidget.h"
#include "ui_devicewidget.h"

DeviceWidget::DeviceWidget(Device* device, QWidget *parent) :
    QWidget(parent),
    m_device(device),
    ui(new Ui::DeviceWidget)
{
    ui->setupUi(this);
    setControls();
}

DeviceWidget::~DeviceWidget()
{
    delete ui;
}

void DeviceWidget::setControls(){
    ui->textEdit->setText(m_device->description());
    ui->lbPrice->setText(QString::number(m_device->price(),'f',2) + " PLN");
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device->image()));
}

void DeviceWidget::setDevice(Device* device)
{
    m_device = device;
}


void DeviceWidget::on_btnAddToCart_clicked()
{
    Cart::instance()->addDevice(m_device);
}

