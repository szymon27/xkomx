#include "cartwidget.h"
#include "ui_cartwidget.h"

CartWidget::CartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CartWidget)
{
    ui->setupUi(this);
    ui->saCart->takeWidget();
    ui->saCart->setWidget(ui->verticalLayoutWidget);
}

CartWidget::~CartWidget()
{
    delete ui;
}

void CartWidget::setUpWidget()
{
    while(ui->vlCart->count() > 0)
        delete ui->vlCart->takeAt(0);

    QVector<Device*> cart = Cart::instance()->cartList(); //Zmiana na koszyk usera
    for(int i = 0; i < cart.size(); i++) {
        CartDeviceWidget *deviceWidget = new CartDeviceWidget();
        deviceWidget->setCartDevice(cart.at(i));
        ui->vlCart->addWidget(deviceWidget);
    }
}

void CartWidget::on_btnBuy_clicked()
{
    //QLayoutItem* item;
    //while ( ( item = ui->vlCart->takeAt( 0 ) ) != NULL )
    //{
    //    delete item->widget();
    //    delete item;
    //}
    //ShipmentWidget *shipmentWidget = new ShipmentWidget();
    //shipmentWidget->setShipmentInfo();
    //ui->vlCart->addWidget(shipmentWidget);
}

