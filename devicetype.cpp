#include "devicetype.h"

QString deviceTypeToString(DeviceType deviceType) {
    switch(deviceType){
        case DeviceType::Computer: return "Computer";
        case DeviceType::Keyboard: return "Keyboard";
        case DeviceType::Monitor: return "Monitor";
        case DeviceType::Mouse: return "Mouse";
        default: return "Unknown";
    }
}

DeviceType stringToDeviceType(QString deviceType)
{
    deviceType = deviceType.toUpper();
    if(deviceType == "COMPUTER") return DeviceType::Computer;
    else if(deviceType == "KEYBOARD") return DeviceType::Keyboard;
    else if(deviceType == "MONITOR") return DeviceType::Monitor;
    else if(deviceType == "MOUSE") return DeviceType::Mouse;
    else return DeviceType::Unknown;
}
