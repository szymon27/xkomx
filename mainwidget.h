#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "device.h"
#include "dbmanager.h"
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

private slots:
    void on_cbxDeviceType_currentTextChanged(const QString &arg1);

    void on_cbxProducer_currentTextChanged(const QString &arg1);

    void on_cbxSorting_currentTextChanged(const QString &arg1);

    void on_btnSearch_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWidget *ui;
    void fillCombo();
};

#endif // MAINWIDGET_H
