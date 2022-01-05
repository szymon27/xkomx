#ifndef DEVICETYPE_H
#define DEVICETYPE_H
#include <QString>

enum DeviceType {
    Monitor = 1,
    Computer = 2,
    Mouse = 3,
    Keyboard = 4
};
QString deviceTypeToString(DeviceType deviceType);
#endif // DEVICETYPE_H
