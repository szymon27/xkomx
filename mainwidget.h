#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "device.h"
#include "DbManager.h"
#include "devicewidget.h"
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void setUpWidget();
private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
