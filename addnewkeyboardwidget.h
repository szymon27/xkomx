#ifndef ADDNEWKEYBOARDWIDGET_H
#define ADDNEWKEYBOARDWIDGET_H

#include <QWidget>
#include "idevicedetails.h"
#include "keyboardtype.h"

namespace Ui {
class AddNewKeyboardWidget;
}

class AddNewKeyboardWidget : public QWidget, public IDeviceDetails
{
    Q_OBJECT

public:
    explicit AddNewKeyboardWidget(QWidget *parent = nullptr);
    ~AddNewKeyboardWidget();
    QString GetDeviceDescription() override;
private:
    Ui::AddNewKeyboardWidget *ui;
    void fillCombo();
};

#endif // ADDNEWKEYBOARDWIDGET_H
