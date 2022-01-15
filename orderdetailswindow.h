#ifndef ORDERDETAILSWINDOW_H
#define ORDERDETAILSWINDOW_H

#include <QDialog>

namespace Ui {
class OrderDetailsWindow;
}

class OrderDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDetailsWindow(QWidget *parent = nullptr);
    ~OrderDetailsWindow();

private:
    Ui::OrderDetailsWindow *ui;
};

#endif // ORDERDETAILSWINDOW_H
