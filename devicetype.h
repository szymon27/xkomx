#ifndef DEVICETYPE_H
#define DEVICETYPE_H
#include <QString>

enum DeviceType {
    Monitor = 1,
    Computer = 2,
    Mouse = 3,
    Keyboard = 4,
    Unknown = 5
};
QString deviceTypeToString(DeviceType deviceType);
DeviceType stringToDeviceType(QString deviceType);
#endif // DEVICETYPE_H
