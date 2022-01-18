#include "addeditdevicewindow.h"
#include "ui_addeditdevicewindow.h"
#include <QDebug>
AddEditDeviceWindow::AddEditDeviceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceWindow)
{
    ACTION = Action::Adding;
    ui->setupUi(this);
    fillCombo();
}

AddEditDeviceWindow::AddEditDeviceWindow(Device* device, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceWindow),
    m_device(device)
{
    ACTION = Action::Editing;
    ui->setupUi(this);
    fillCombo();
    ui->leModel->setText(m_device->model());
    ui->leProducer->setText(m_device->producer());
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device->image()));
}

AddEditDeviceWindow::~AddEditDeviceWindow()
{
    delete ui;
    delete detailsWidget;
}

void AddEditDeviceWindow::fillCombo()
{
    QList<QString> list;
    list.append(deviceTypeToString(DeviceType::Computer));
    list.append(deviceTypeToString(DeviceType::Keyboard));
    list.append(deviceTypeToString(DeviceType::Mouse));
    list.append(deviceTypeToString(DeviceType::Monitor));
    ui->cbxDeviceType->addItems(list);
}

void AddEditDeviceWindow::on_cbxDeviceType_currentIndexChanged(const QString &arg1)
{
    if(ui->cbxDeviceType->isEnabled()){
            QLayoutItem* item;
            if ( ( item = ui->verticalLayout_2->takeAt( 0 ) ) != NULL)
            {
                delete item->widget();
                delete item;
                item = nullptr;
            }
    switch (stringToDeviceType(arg1)) {
    case DeviceType::Computer:
        detailsWidget = new AddEditComputerWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Keyboard:
        detailsWidget = new AddEditKeyboardWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Monitor:
        detailsWidget = new AddEditMonitorWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Mouse:
        detailsWidget = new AddEditMouseWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Unknown: return;
    }
    }
}


void AddEditDeviceWindow::on_btnCancel_clicked()
{
    this->close();
}


void AddEditDeviceWindow::on_btnConfirm_clicked()
{

    DeviceType deviceType = stringToDeviceType(ui->cbxDeviceType->currentText());
    QString producer = ui->leProducer->text();
    QString model = ui->leModel->text();
    QString description = ((IDeviceDetails*)detailsWidget)->GetDeviceDescription();
    int count = ui->sbxCount->value();
    double price = ui->sbxPrice->value();
    QFile file(imagePath);
    QByteArray byteArray;
    if(file.open(QIODevice::ReadOnly)){
        byteArray = file.readAll();
        file.close();
        qDebug() << byteArray.length();
    }

    ImageType imageType = imagePath.right(3) == "png" ? ImageType::PNG : ImageType::JPG;
    if(DbManager::instance()->addNewDevice(deviceType, producer, model, description, count, price, byteArray, imageType)){
        QMessageBox::information(this, "XKOMX", "New device added successfully!");
        emit on_btnCancel_clicked();
    }
    else
        QMessageBox::warning(this, "XKOMX", "New device addition failed!");

}


void AddEditDeviceWindow::on_btnAddImage_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this, "Choose Image file", "", "Images (*.png *.jpg)");
    if(imagePath.isEmpty()){
        QMessageBox::warning(this, "XKOMX", "Wrong file!");
        return;
    }
    ui->lbImage->setPixmap(QPixmap::fromImage(QImage(imagePath)));
}

