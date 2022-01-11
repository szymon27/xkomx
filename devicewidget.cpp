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
    ui->lbProducer->setText(m_device->producer());
    ui->lbModel->setText(m_device->model());
    ui->lbPrice->setText(QString::number(m_device->price()));
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device->image()));
    ui->lbType->setText(deviceTypeToString(m_device->deviceType()));
}

void DeviceWidget::setDevice(Device* device)
{
    m_device = device;
}

void DeviceWidget::on_btnDetails_clicked()
{
    DeviceDetailsWindow *window = new DeviceDetailsWindow(m_device);
    window->exec();
    delete window;
}


void DeviceWidget::on_btnAddToCart_clicked()
{
    Cart::instance()->addDevice(m_device);
}

