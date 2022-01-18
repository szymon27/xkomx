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

    QVector<Device*> devices = DbManager::instance()->devicesList();
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}

void MainWidget::fillCombo()
{
    QList<QString> list;
    list.append(deviceTypeToString(DeviceType::Computer));
    list.append(deviceTypeToString(DeviceType::Keyboard));
    list.append(deviceTypeToString(DeviceType::Mouse));
    list.append(deviceTypeToString(DeviceType::Monitor));
    ui->cbxDeviceType->addItems(list);

    list.clear();
    list = DbManager::instance()->getProducers();
    ui->cbxProducer->addItems(list);

    list.clear();
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

void MainWidget::on_cbxDeviceType_currentTextChanged(const QString &arg1)
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->filterDeviceType(stringToDeviceType(arg1));
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}

void MainWidget::on_cbxProducer_currentTextChanged(const QString &arg1)
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->filterProducer(arg1);
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}


void MainWidget::on_cbxSorting_currentTextChanged(const QString &arg1)
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->sorted(stringToSorting(arg1));
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}


void MainWidget::on_btnSearch_clicked()
{
    QLayoutItem* item;
    while ( ( item = ui->vlShop->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->search(ui->leSearch->text());
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}


void MainWidget::on_btnClear_clicked()
{
    ui->cbxDeviceType->setDisabled(true);
    ui->cbxProducer->setDisabled(true);
    ui->cbxSorting->setDisabled(true);

    ui->cbxDeviceType->setCurrentIndex(-1);
    ui->cbxProducer->setCurrentIndex(-1);
    ui->cbxSorting->setCurrentIndex(-1);

    ui->cbxDeviceType->setEnabled(true);
    ui->cbxProducer->setEnabled(true);
    ui->cbxSorting->setEnabled(true);

    ui->leSearch->clear();

    setUpWidget();
}

