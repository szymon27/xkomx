#include "addeditcomputerwidget.h"
#include "ui_addeditcomputerwidget.h"

AddEditComputerWidget::AddEditComputerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditComputerWidget)
{
    ui->setupUi(this);
}

AddEditComputerWidget::AddEditComputerWidget(class::Computer* device, QWidget *parent):
    QWidget(parent),
    ui(new Ui::AddEditComputerWidget)
{
    ui->setupUi(this);
    ui->leDisc->setText(device->disc());
    ui->leGraphicsCard->setText(device->graphicsCard());
    ui->leRam->setText(device->ram());
    ui->leProcessor->setText(device->processor());
    ui->lePowerSupply->setText(device->powerSupply());
    ui->leSystem->setText(device->system());
}

AddEditComputerWidget::~AddEditComputerWidget()
{
    delete ui;
}

QString AddEditComputerWidget::GetDeviceDescription()
{
    QString cpu = ui->leProcessor->text();
    QString ram = ui->leRam->text();
    QString gpu = ui->leGraphicsCard->text();
    QString disc = ui->leDisc->text();
    QString power = ui->lePowerSupply->text();
    QString sys = ui->leSystem->text();

    if(cpu==""){
        QMessageBox::warning(this, "XKOMX", "Cpu textbox cannot be empty");
        return 0;
    }
    if(ram==""){
        QMessageBox::warning(this, "XKOMX", "Ram textbox cannot be empty");
        return 0;
    }
    if(gpu==""){
        QMessageBox::warning(this, "XKOMX", "Gpu textbox cannot be empty");
        return 0;
    }
    if(disc==""){
        QMessageBox::warning(this, "XKOMX", "Disc textbox cannot be empty");
        return 0;
    }
    if(power==""){
        QMessageBox::warning(this, "XKOMX", "Power supply textbox cannot be empty");
        return 0;
    }
    if(sys==""){
        QMessageBox::warning(this, "XKOMX", "System textbox cannot be empty");
        return 0;
    }

    return QString("{\"processor\":\"%1\",\"ram\":\"%2\",\"graphics card\":\"%3\",\"disc\":\"%4\",\"power supply\":\"%5\",\"system\":\"%6\"}")
            .arg(cpu, ram, gpu, disc, power, sys);
}
