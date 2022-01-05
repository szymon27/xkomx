#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(User, QWidget *parent = nullptr);
    ~UserWidget();;

private:
    Ui::UserWidget *ui;
    User m_user;
    void setControls();
};

#endif // USERWIDGET_H
