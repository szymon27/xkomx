#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->saShop->takeWidget();
    ui->saShop->setWidget(ui->verticalLayoutWidget);
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

    QVector<Device> devices = DbManager::getInstance()->getDevicesList();
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget(devices.at(i));
        //productWidget->setDevice(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}
