#include "shipmentwidget.h"
#include "ui_shipmentwidget.h"

ShipmentWidget::ShipmentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShipmentWidget)
{
    ui->setupUi(this);
}

ShipmentWidget::~ShipmentWidget()
{
    delete ui;
}

void ShipmentWidget::setShipmentInfo(){
    ui->leName->setText(CurrentUser::instance()->user().name());
    ui->leSurname->setText(CurrentUser::instance()->user().surname());
    ui->leCountry->setText(CurrentUser::instance()->user().country());
    ui->lePostalCode->setText(CurrentUser::instance()->user().postCode());
    ui->leAddress->setText(CurrentUser::instance()->user().address());
    ui->leCity->setText(CurrentUser::instance()->user().city());
}
