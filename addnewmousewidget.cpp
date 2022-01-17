#include "addnewmousewidget.h"
#include "ui_addnewmousewidget.h"

AddNewMouseWidget::AddNewMouseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewMouseWidget)
{
    ui->setupUi(this);
}

AddNewMouseWidget::~AddNewMouseWidget()
{
    delete ui;
}

QString AddNewMouseWidget::GetDeviceDescription()
{
    QString wireless = ui->chbWireless->isChecked() ? "true" : "false";
    QString keys = QString::number(ui->sbxKeys->value());
    QString DPI = QString::number(ui->sbxDPI->value());
    return QString("{\"wireless\":%1,\"keys\":%2,\"dpi\":%3}").arg(wireless, keys, DPI);
}
