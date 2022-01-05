#include "devicewidget.h"
#include "ui_devicewidget.h"

DeviceWidget::DeviceWidget(Device device, QWidget *parent) :
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
    ui->lbProducer->setText(m_device.m_producer);
    ui->lbModel->setText(m_device.m_model);
    ui->lbPrice->setText(QString::number(m_device.m_price));
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device.m_image));
    ui->lbType->setText(deviceTypeToString(m_device.m_deviceType));
}

void DeviceWidget::setDevice(Device device)
{
    m_device = device;
}

void DeviceWidget::on_btnDetails_clicked()
{
    DeviceDetailsWindow *window = new DeviceDetailsWindow(m_device);
    window->exec();
    delete window;
}

