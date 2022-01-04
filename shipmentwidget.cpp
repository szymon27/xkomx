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
    ui->leName->setText(CurrentUser::getInstance()->getUser().name());
    ui->leSurname->setText(CurrentUser::getInstance()->getUser().surname());
    ui->leCountry->setText(CurrentUser::getInstance()->getUser().country());
    ui->lePostalcode->setText(CurrentUser::getInstance()->getUser().postCode());
    ui->leAddress->setText(CurrentUser::getInstance()->getUser().address());
    ui->leCity->setText(CurrentUser::getInstance()->getUser().city());
}
