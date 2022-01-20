#include "addeditdevicewindow.h"
#include "ui_addeditdevicewindow.h"
AddEditDeviceWindow::AddEditDeviceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceWindow)
{
    ACTION = Action::Adding;
    ui->setupUi(this);
    fillCombo();
}

AddEditDeviceWindow::AddEditDeviceWindow(Device *device, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceWindow),
    m_device(device)
{
    ACTION = Action::Editing;
    ui->setupUi(this);
        ui->cbxDeviceType->setDisabled(true);
    fillCombo();
    ui->leModel->setText(m_device->model());
    ui->leProducer->setText(m_device->producer());
    ui->lbImage->setPixmap(QPixmap::fromImage(m_device->image()));
    ui->sbxCount->setValue(m_device->count());
    ui->sbxPrice->setValue(m_device->price());
    ui->cbxDeviceType->setCurrentText(deviceTypeToString(m_device->deviceType()));
    switch (stringToDeviceType(ui->cbxDeviceType->currentText())) {
    case Monitor:
        detailsWidget = new AddEditMonitorWidget((class::Monitor*)m_device);
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case Computer:
        detailsWidget = new AddEditComputerWidget((class::Computer*)m_device);
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case Mouse:
        detailsWidget = new AddEditMouseWidget((class::Mouse*)m_device);
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case Keyboard:
        detailsWidget = new AddEditKeyboardWidget((class::Keyboard*)m_device);
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case Unknown:
        return;
    }
    ui->cbxDeviceType->setEnabled(true);
}

AddEditDeviceWindow::~AddEditDeviceWindow()
{
    delete ui;
    delete detailsWidget;
    delete m_device;
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
    flag_image = false;
    this->close();
}


void AddEditDeviceWindow::on_btnConfirm_clicked()
{

    DeviceType deviceType = stringToDeviceType(ui->cbxDeviceType->currentText());
    QString producer = ui->leProducer->text();
    QString model = ui->leModel->text();
    if(producer==""){
        QMessageBox::warning(this, "XKOMX", "Producer textbox cannot be empty");
        return;
    }
    if(model==""){
        QMessageBox::warning(this, "XKOMX", "Model textbox cannot be empty");
        return;
    }
    QString description;
    switch (stringToDeviceType(ui->cbxDeviceType->currentText())) {
    case DeviceType::Computer:
        description = ((AddEditComputerWidget*)detailsWidget)->GetDeviceDescription();
        break;
    case DeviceType::Keyboard:
        description = ((AddEditKeyboardWidget*)detailsWidget)->GetDeviceDescription();
        break;
    case DeviceType::Monitor:
        description = ((AddEditMonitorWidget*)detailsWidget)->GetDeviceDescription();
        break;
    case DeviceType::Mouse:
        description = ((AddEditMouseWidget*)detailsWidget)->GetDeviceDescription();
        break;
    case DeviceType::Unknown: return;
    }

    int count = ui->sbxCount->value();
    double price = ui->sbxPrice->value();

    QFile file(imagePath);
    QByteArray byteArray;
    ImageType imageType = imagePath.right(3) == "png" ? ImageType::PNG : ImageType::JPG;
    const QPixmap* pixmap = ui->lbImage->pixmap();
        if(pixmap){
            QImage image(pixmap->toImage());
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        imageType == ImageType::PNG ? QPixmap::fromImage(image).save(&buffer, "PNG") : QPixmap::fromImage(image).save(&buffer, "JPG");
        }
        else{

            return;
        }
    if(ACTION == Action::Adding){
        if(DbManager::instance()->addNewDevice(deviceType, producer, model, description, count, price, byteArray, imageType)){
            QMessageBox::information(this, "XKOMX", "New device added successfully!");
         emit on_btnCancel_clicked();
    }
    else
        QMessageBox::warning(this, "XKOMX", "New device addition failed!");
    }

    if(ACTION == Action::Editing){
        if(DbManager::instance()->editDevice(m_device->id(), deviceType, producer, model, description, count, price, byteArray, imageType)){
            QMessageBox::information(this, "XKOMX", "Editing device ended successfully!");
         emit on_btnCancel_clicked();
    }
    else
        QMessageBox::warning(this, "XKOMX", "Editing device failed!");
    }

}


void AddEditDeviceWindow::on_btnAddImage_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this, "Choose Image file", "", "Images (*.png *.jpg)");
    if(imagePath.isEmpty()){
        flag_image = false;
        QMessageBox::warning(this, "XKOMX", "Wrong file!");
        return;
    }
    flag_image = true;
    ui->lbImage->setPixmap(QPixmap::fromImage(QImage(imagePath)));
}

