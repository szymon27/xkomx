#include "addnewkeyboardwidget.h"
#include "ui_addnewkeyboardwidget.h"

AddNewKeyboardWidget::AddNewKeyboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewKeyboardWidget)
{
    ui->setupUi(this);
    fillCombo();
}

AddNewKeyboardWidget::~AddNewKeyboardWidget()
{
    delete ui;
}

QString AddNewKeyboardWidget::GetDeviceDescription()
{
    QString wireless = ui->chxWireless->isChecked() ? "true" : "false";
    QString lighting = ui->chxLighting->isChecked() ? "true" : "false";
    QString numpad = ui->chxNumpad->isChecked() ? "true" : "false";
    QString type = ui->cbxKeyboardType->currentText();
    return QString("{\"wireless\":%1,\"keyboard type\":\"%2\",\"lighting\":%3,\"numpad\":%4}").arg(wireless, type, lighting, numpad);
}

void AddNewKeyboardWidget::fillCombo()
{
    QList<QString> list;
    list.append(keyboardTypeToString(KeyboardType::Mechanical));
    list.append(keyboardTypeToString(KeyboardType::Membrane));
    list.append(keyboardTypeToString(KeyboardType::Hybrid));
    list.append(keyboardTypeToString(KeyboardType::Optical));
    list.append(keyboardTypeToString(KeyboardType::Other));
    ui->cbxKeyboardType->addItems(list);
}
