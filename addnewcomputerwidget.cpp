#include "addnewcomputerwidget.h"
#include "ui_addnewcomputerwidget.h"

AddNewComputerWidget::AddNewComputerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewComputerWidget)
{
    ui->setupUi(this);
}

AddNewComputerWidget::~AddNewComputerWidget()
{
    delete ui;
}

QString AddNewComputerWidget::GetDeviceDescription()
{
    QString cpu = ui->leProcessor->text();
    QString ram = ui->leRam->text();
    QString gpu = ui->leGraphicsCard->text();
    QString disc = ui->leDisc->text();
    QString power = ui->lePowerSupply->text();
    QString sys = ui->leSystem->text();
    return QString("{\"processor\":\"%1\",\"ram\":\"%2\",\"graphics card\":\"%3\",\"disc\":\"%4\",\"power supply\":\"%5\",\"system\":\"%6\"}")
            .arg(cpu, ram, gpu, disc, power, sys);
}
