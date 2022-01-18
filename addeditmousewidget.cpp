#include "addeditmousewidget.h"
#include "ui_addeditmousewidget.h"

AddEditMouseWidget::AddEditMouseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditMouseWidget)
{
    ui->setupUi(this);
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
