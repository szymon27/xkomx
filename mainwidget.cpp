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
    while(ui->vlShop->count() > 0)
        delete ui->vlShop->takeAt(0);

    QVector<Device> devices = DbManager::getInstance()->getDevicesList();
    for(int i = 0; i < devices.size(); i++) {
        DeviceWidget *productWidget = new DeviceWidget();
        productWidget->setDevice(devices.at(i));
        ui->vlShop->addWidget(productWidget);
    }
}
