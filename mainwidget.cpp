#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->saShop->takeWidget();
    ui->saShop->setWidget(ui->verticalLayoutWidget);
    ui->cbxDeviceType->setDisabled(true);
    ui->cbxProducer->setDisabled(true);
    ui->cbxSorting->setDisabled(true);
    fillCombo();
}

MainWidget::~MainWidget()
{
    delete ui;
    foreach (Device *device, devices) {
    delete device;
    }
    devices.clear();
}

void MainWidget::setUpWidget()
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    foreach (Device *device, devices) {
    delete device;
    }
    devices.clear();
    devices = DbManager::instance()->devicesList();
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}

void MainWidget::fillCombo()
{
    QList<QString> list;
    list.append("Device type");
    list.append(deviceTypeToString(DeviceType::Computer));
    list.append(deviceTypeToString(DeviceType::Keyboard));
    list.append(deviceTypeToString(DeviceType::Mouse));
    list.append(deviceTypeToString(DeviceType::Monitor));
    ui->cbxDeviceType->addItems(list);

    list.clear();
    list.append("Producer");
    list += DbManager::instance()->getProducers();
    ui->cbxProducer->addItems(list);

    list.clear();
    list.append("Sorting");
    list.append((sortingToString(Sorting::AZProd)));
    list.append((sortingToString(Sorting::ZAProd)));
    list.append((sortingToString(Sorting::AZModel)));
    list.append((sortingToString(Sorting::ZAModel)));
    list.append((sortingToString(Sorting::PriceAsc)));
    list.append((sortingToString(Sorting::PriceDsc)));
    ui->cbxSorting->addItems(list);

    ui->cbxDeviceType->setEnabled(true);
    ui->cbxProducer->setEnabled(true);
    ui->cbxSorting->setEnabled(true);
}

void MainWidget::filter()
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }
    QString sqlStatement = "SELECT * FROM devices WHERE ";
    if(ui->cbxDeviceType->currentIndex()>0){
        sqlStatement += "device_type_id = " + QString::number((int)stringToDeviceType(ui->cbxDeviceType->currentText())) + " AND ";
    }
    if(ui->cbxProducer->currentIndex()>0){
        sqlStatement += "producer = \"" + ui->cbxProducer->currentText() + "\" AND ";
    }
    if(ui->leSearch->text().size()>0){
        QString search = ui->leSearch->text();
        sqlStatement += "(model like '%" + search + "%' OR producer like '%" + search + "%') AND ";
    }
    sqlStatement += "1 = 1 ";
    if(ui->cbxSorting->currentIndex()>0){
        sqlStatement += "ORDER BY " + sortingToSQL(stringToSorting(ui->cbxSorting->currentText()));
    }
    foreach (Device *device, devices) {
    delete device;
    }
    devices.clear();
    devices = DbManager::instance()->filtredList(sqlStatement);
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}

void MainWidget::on_cbxDeviceType_currentTextChanged()
{
    filter();
}

void MainWidget::on_cbxProducer_currentTextChanged()
{
    filter();
}


void MainWidget::on_cbxSorting_currentTextChanged()
{
    filter();
}


void MainWidget::on_btnSearch_clicked()
{
    filter();
}


void MainWidget::on_btnClear_clicked()
{
    ui->cbxDeviceType->setDisabled(true);
    ui->cbxProducer->setDisabled(true);
    ui->cbxSorting->setDisabled(true);

    ui->cbxDeviceType->setCurrentIndex(0);
    ui->cbxProducer->setCurrentIndex(0);
    ui->cbxSorting->setCurrentIndex(0);

    ui->cbxDeviceType->setEnabled(true);
    ui->cbxProducer->setEnabled(true);
    ui->cbxSorting->setEnabled(true);

    ui->leSearch->clear();

    setUpWidget();
}

