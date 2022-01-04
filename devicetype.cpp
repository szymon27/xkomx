#include "devicetype.h"

QString deviceTypeToString(DeviceType deviceType) {
    switch(deviceType){
        case DeviceType::Computer: return "Computer";
        case DeviceType::Keyboard: return "Keyboard";
        case DeviceType::Monitor: return "Monitor";
        case DeviceType::Mouse: return "Mouse";
    }
}
