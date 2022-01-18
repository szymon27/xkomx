#include "addeditmonitorwidget.h"
#include "ui_addeditmonitorwidget.h"

AddEditMonitorWidget::AddEditMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditMonitorWidget)
{
    ui->setupUi(this);
    fillCombo();
}

AddEditMonitorWidget::AddEditMonitorWidget(class::Monitor* device, QWidget *parent):
    QWidget(parent),
    ui(new Ui::AddEditMonitorWidget)
{
    ui->setupUi(this);
    fillCombo();

    ui->cbxDisplayType->setCurrentText(displayTypeToString(device->displayType()));
    ui->leResolution->setText(device->resolution());
    ui->sbxRefreshRate->setValue(device->refreshRate());
    ui->sbxScreenSize->setValue(device->screenSize());
}

AddEditMonitorWidget::~AddEditMonitorWidget()
{
    delete ui;
}

QString AddEditMonitorWidget::GetDeviceDescription()
{
    QString refreshRate = QString::number(ui->sbxRefreshRate->value());
    QString screenSize = QString::number(ui->sbxScreenSize->value());
    QString res = ui->leResolution->text();
    QString type = ui->cbxDisplayType->currentText();
    return QString("{\"refresh rate\":%1,\"screen size\":%2,\"resolution\":\"%3\",\"display type\":\"%4\"}").arg(refreshRate, screenSize, res, type);
}

void AddEditMonitorWidget::fillCombo()
{
    QList<QString> list;
    list.append(displayTypeToString(DisplayType::IPS));
    list.append(displayTypeToString(DisplayType::VA));
    list.append(displayTypeToString(DisplayType::TN));
    list.append(displayTypeToString(DisplayType::OLED));
    list.append(displayTypeToString(DisplayType::LCD));
    ui->cbxDisplayType->addItems(list);
}
