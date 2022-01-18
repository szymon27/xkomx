#include "addeditmousewidget.h"
#include "ui_addeditmousewidget.h"

AddEditMouseWidget::AddEditMouseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditMouseWidget)
{
    ui->setupUi(this);
}

AddEditMouseWidget::AddEditMouseWidget(class::Mouse* device, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditMouseWidget)
{
    ui->setupUi(this);
    ui->chbWireless->setChecked(device->wireless());
    ui->sbxDPI->setValue(device->dpi());
    ui->sbxKeys->setValue(device->keys());
}

AddEditMouseWidget::~AddEditMouseWidget()
{
    delete ui;
}

QString AddEditMouseWidget::GetDeviceDescription()
{
    QString wireless = ui->chbWireless->isChecked() ? "true" : "false";
    QString keys = QString::number(ui->sbxKeys->value());
    QString DPI = QString::number(ui->sbxDPI->value());
    return QString("{\"wireless\":%1,\"keys\":%2,\"dpi\":%3}").arg(wireless, keys, DPI);
}
