#include "addnewdevicewindow.h"
#include "ui_addnewdevicewindow.h"
#include <QDebug>
AddNewDeviceWindow::AddNewDeviceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDeviceWindow)
{
    ui->setupUi(this);
    fillCombo();
}

AddNewDeviceWindow::~AddNewDeviceWindow()
{
    delete ui;
    delete detailsWidget;
}

void AddNewDeviceWindow::fillCombo()
{
    QList<QString> list;
    list.append(deviceTypeToString(DeviceType::Computer));
    list.append(deviceTypeToString(DeviceType::Keyboard));
    list.append(deviceTypeToString(DeviceType::Mouse));
    list.append(deviceTypeToString(DeviceType::Monitor));
    ui->cbxDeviceType->addItems(list);
}

void AddNewDeviceWindow::on_cbxDeviceType_currentIndexChanged(const QString &arg1)
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
        detailsWidget = new AddNewComputerWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Keyboard:
        detailsWidget = new AddNewKeyboardWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Monitor:
        detailsWidget = new AddNewMonitorWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Mouse:
        detailsWidget = new AddNewMouseWidget();
        ui->verticalLayout_2->addWidget(detailsWidget);
        break;
    case DeviceType::Unknown: return;
    }
    }
}


void AddNewDeviceWindow::on_btnCancel_clicked()
{
    QLayoutItem* item;
    if ( ( item = ui->verticalLayout_2->takeAt( 0 ) ) != NULL)
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }
    this->close();
}


void AddNewDeviceWindow::on_btnConfirm_clicked()
{

    DeviceType deviceType = stringToDeviceType(ui->cbxDeviceType->currentText());
    QString producer = ui->leProducer->text();
    QString model = ui->leModel->text();
    QString description = "a";//((IDeviceDetails*)detailsWidget)->GetDeviceDescription();
    int count = ui->sbxCount->value();
    double price = ui->sbxPrice->value();
    QByteArray byteArray = file->readAll();
    ImageType imageType = imagePath.right(3) == "png" ? ImageType::PNG : ImageType::JPG;
    //if(DbManager::instance()->addNewDevice(deviceType, producer, model, description, count, price, imagePath.replace("/", "\\"), imageType)){
    //    QMessageBox::information(this, "XKOMX", "New device added successfully!");
    //    emit on_btnCancel_clicked();
    if(DbManager::instance()->addNewDevice(deviceType, producer, model, description, count, price, byteArray, imageType)){
        QMessageBox::information(this, "XKOMX", "New device added successfully!");
        emit on_btnCancel_clicked();
    }
    else
        QMessageBox::warning(this, "XKOMX", "New device addition failed!");

}


void AddNewDeviceWindow::on_btnAddImage_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this, "Choose Image file", "", "Images (*.png *.jpg)");
    if(imagePath.isEmpty()){
        QMessageBox::warning(this, "XKOMX", "Wrong file!");
        return;
    }
    ui->lbImage->setPixmap(QPixmap::fromImage(QImage(imagePath)));
    file = new QFile(imagePath);
        qDebug() << QVariant(imagePath).toString();
}

