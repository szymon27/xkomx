#ifndef PROGRAM_H
#define PROGRAM_H
#include <QObject>

class MainWindow;
class Program : public QObject {
    Q_OBJECT

public:
    explicit Program(QObject* parent = nullptr);
    void setGUI(MainWindow* ui = nullptr);

private:
    MainWindow* GUI = nullptr;
};

#endif // PROGRAM_H
