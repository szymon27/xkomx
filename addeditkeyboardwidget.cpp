#include "addeditkeyboardwidget.h"
#include "ui_addeditkeyboardwidget.h"

AddEditKeyboardWidget::AddEditKeyboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEditKeyboardWidget)
{
    ui->setupUi(this);
    fillCombo();
}

AddEditKeyboardWidget::AddEditKeyboardWidget(class::Keyboard* device, QWidget *parent):
    QWidget(parent),
    ui(new Ui::AddEditKeyboardWidget)
{
    ui->setupUi(this);
    fillCombo();
    ui->cbxKeyboardType->setCurrentText(keyboardTypeToString(device->keyboardType()));
    ui->chxLighting->setChecked(device->lighting());
    ui->chxNumpad->setChecked(device->numpad());
    ui->chxWireless->setChecked(device->wireless());
}

AddEditKeyboardWidget::~AddEditKeyboardWidget()
{
    delete ui;
}

QString AddEditKeyboardWidget::GetDeviceDescription()
{
    QString wireless = ui->chxWireless->isChecked() ? "true" : "false";
    QString lighting = ui->chxLighting->isChecked() ? "true" : "false";
    QString numpad = ui->chxNumpad->isChecked() ? "true" : "false";
    QString type = ui->cbxKeyboardType->currentText();
    return QString("{\"wireless\":%1,\"keyboard type\":\"%2\",\"lighting\":%3,\"numpad\":%4}").arg(wireless, type, lighting, numpad);
}

void AddEditKeyboardWidget::fillCombo()
{
    QList<QString> list;
    list.append(keyboardTypeToString(KeyboardType::Mechanical));
    list.append(keyboardTypeToString(KeyboardType::Membrane));
    list.append(keyboardTypeToString(KeyboardType::Hybrid));
    list.append(keyboardTypeToString(KeyboardType::Optical));
    list.append(keyboardTypeToString(KeyboardType::Other));
    ui->cbxKeyboardType->addItems(list);
}
