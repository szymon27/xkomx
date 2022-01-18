#ifndef ADDEDITKEYBOARDWIDGET_H
#define ADDEDITKEYBOARDWIDGET_H

#include <QWidget>
#include "idevicedetails.h"
#include "keyboard.h"
#include "keyboardtype.h"

namespace Ui {
class AddEditKeyboardWidget;
}

class AddEditKeyboardWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddEditKeyboardWidget(QWidget *parent = nullptr);
    explicit AddEditKeyboardWidget(class::Keyboard* device, QWidget *parent = nullptr);
    ~AddEditKeyboardWidget();
    QString GetDeviceDescription() override;
private:
    Ui::AddEditKeyboardWidget *ui;
    void fillCombo();
};

#endif // ADDEDITKEYBOARDWIDGET_H
