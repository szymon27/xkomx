#include "cartdevicewidget.h"
#include "ui_cartdevicewidget.h"

CartDeviceWidget::CartDeviceWidget(CartElement cartElement, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CartDeviceWidget),
    m_cartElement(cartElement)
{
    ui->setupUi(this);
    ui->sbxQuantity->setMaximum(cartElement.device->count());
    ui->sbxQuantity->setValue(cartElement.count); //zmiana na ilosc w koszyku z bazy
    ui->lbProducer->setText(cartElement.device->producer());
    ui->lbModel->setText(cartElement.device->model());
    ui->lbPrice->setText(QString::number(cartElement.device->price(),'f',2) + " PLN");
    ui->lbImage->setPixmap(QPixmap::fromImage(cartElement.device->image()));
    ui->lbTotalPrice->setText(QString::number(cartElement.device->price() * cartElement.count * 1,'f',2)+ " PLN"); // zmiana na sbxQuantity.getValue()
}

CartDeviceWidget::~CartDeviceWidget()
{
    delete ui;
}

void CartDeviceWidget::on_sbxQuantity_valueChanged(int count)
{
    Cart::instance()->setCountOfCartElement(m_cartElement.device->id(), count);
    ui->lbTotalPrice->setText(QString::number(m_cartElement.device->price() * count * 1,'f',2)+ " PLN");
    emit changePrice();
}


void CartDeviceWidget::on_pushButton_clicked()
{
    Cart::instance()->removeCartElementById(m_cartElement.device->id());
    emit update();
}

