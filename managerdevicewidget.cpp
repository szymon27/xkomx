#include "managerdevicewidget.h"
#include "ui_managerdevicewidget.h"

ManagerDeviceWidget::ManagerDeviceWidget(Device* device, QWidget *parent) :
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
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device->image()));
    ui->lbProducer->setText(m_device->producer());
    ui->lbModel->setText(m_device->model());
    ui->lbType->setText(deviceTypeToString(m_device->deviceType()));
}

void ManagerDeviceWidget::on_btnEdit_clicked()
{
    AddEditDeviceWindow *window = new AddEditDeviceWindow(m_device);
    window->exec();
    delete window;
}


void ManagerDeviceWidget::on_pushButton_2_clicked()
{
    if(DbManager::instance()->removeById(m_device->id())){
        QMessageBox::information(this, "XKOMX", "Device removed successfully!");
                emit refresh();
    }
    else
        QMessageBox::warning(this, "XKOMX", "Device removal failed!");

}

