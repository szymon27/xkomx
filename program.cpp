#include "program.h"

Program::Program(QObject *parent)
    :QObject(parent)
{}

void Program::setGUI(MainWindow *ui)
{
    GUI = ui;
}
