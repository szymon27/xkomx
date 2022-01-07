#ifndef DISPLAYTYPE_H
#define DISPLAYTYPE_H
#include <QString>

enum DisplayType {
    IPS = 1,
    VA = 2,
    TN = 3,
    OLED = 4,
    LCD = 5,
    OTHER = 6
};
QString displayTypeToString(DisplayType displayType);
DisplayType stringToDisplayType(QString displayType);

#endif // DISPLAYTYPE_H
