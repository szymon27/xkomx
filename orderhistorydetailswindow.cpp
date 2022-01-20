#include "orderhistorydetailswindow.h"
#include "ui_orderhistorydetailswindow.h"
#include <QtDebug>
OrderHistoryDetailsWindow::OrderHistoryDetailsWindow(int id, QDate d, double p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderHistoryDetailsWindow)
{
    ui->setupUi(this);
    ui->saDevices->takeWidget();
    ui->saDevices->setWidget(ui->verticalLayoutWidget_2);
    ui->lbTotalCost->setText(QString::number(p,'f',2) + " PLN");
    ui->lbDate->setText(d.toString("dd.MM.yyyy"));
    QLayoutItem* item;
    while ( ( item = ui->vlDevices->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<OrderDetails> devices = DbManager::instance()->orderDevices(id);

    for(int i = 0; i < devices.size(); i++) {
        OrderHistoryDeviceWidget *productWidget = new OrderHistoryDeviceWidget(devices.at(i));
        ui->vlDevices->addWidget(productWidget);
    }
}

OrderHistoryDetailsWindow::~OrderHistoryDetailsWindow()
{
    delete ui;
}
