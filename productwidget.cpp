#include "productwidget.h"
#include "ui_productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);
}

ProductWidget::~ProductWidget()
{
    delete ui;
}

void ProductWidget::setProduct(Device device)
{
    ui->lbName->setText(device.m_producer);
    ui->lbPrice->setText(QString::number(device.m_price));
    ui->lbImage->setPixmap(QPixmap::fromImage(device.m_image));
    ui->lbProducer->setText(device.m_description);
}
