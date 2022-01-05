#include "devicedetailswindow.h"
#include "ui_devicedetailswindow.h"

DeviceDetailsWindow::DeviceDetailsWindow(Device device, QWidget *parent) :
    QDialog(parent),
    m_device(device),
    ui(new Ui::DeviceDetailsWindow)
{
    ui->setupUi(this);
    setControls();
}

DeviceDetailsWindow::~DeviceDetailsWindow()
{
    delete ui;
}

void DeviceDetailsWindow::setControls(){
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device.m_image));
    ui->txtDetails->append(m_device.m_producer);
    ui->txtDetails->append(m_device.m_model);
    ui->txtDetails->append(m_device.descriptionToString());
    ui->txtDetails->append(m_device.descriptionToString());
}
