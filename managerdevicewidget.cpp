#include "managerdevicewidget.h"
#include "ui_managerdevicewidget.h"

ManagerDeviceWidget::ManagerDeviceWidget(Device device, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerDeviceWidget),
    m_device(device)
{
    ui->setupUi(this);
    setControls();
}

ManagerDeviceWidget::~ManagerDeviceWidget()
{
    delete ui;
}

void ManagerDeviceWidget::setControls()
{
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device.m_image));
    ui->lbProducer->setText(m_device.m_producer);
    ui->lbModel->setText(m_device.m_model);
    ui->lbType->setText(deviceTypeToString(m_device.m_deviceType));
}
