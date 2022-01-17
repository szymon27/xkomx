#include "addnewmonitorwidget.h"
#include "ui_addnewmonitorwidget.h"

AddNewMonitorWidget::AddNewMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewMonitorWidget)
{
    ui->setupUi(this);
    fillCombo();
}

AddNewMonitorWidget::~AddNewMonitorWidget()
{
    delete ui;
}

QString AddNewMonitorWidget::GetDeviceDescription()
{
    QString refreshRate = QString::number(ui->sbxRefreshRate->value());
    QString screenSize = QString::number(ui->sbxScreenSize->value());
    QString res = ui->leResolution->text();
    QString type = ui->cbxDisplayType->currentText();
    return QString("{\"refresh rate\":%1,\"screen size\":%2,\"resolution\":\"%3\",\"display type\":\"%4\"}").arg(refreshRate, screenSize, res, type);
}

void AddNewMonitorWidget::fillCombo()
{
    QList<QString> list;
    list.append(displayTypeToString(DisplayType::IPS));
    list.append(displayTypeToString(DisplayType::VA));
    list.append(displayTypeToString(DisplayType::TN));
    list.append(displayTypeToString(DisplayType::OLED));
    list.append(displayTypeToString(DisplayType::LCD));
    ui->cbxDisplayType->addItems(list);
}
