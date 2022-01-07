#include "keyboardtype.h"

QString keyboardTypeToString(KeyboardType keyboardType)
{
    switch(keyboardType) {
        case KeyboardType::Mechanical: return "Mechanical";
        case KeyboardType::Membrane: return "Membrane";
        case KeyboardType::Hybrid: return "Hybrid";
        case KeyboardType::Optical: return "Optical";
        default: return "Other";
    }
}

KeyboardType stringToKeyboardType(QString keyboardType)
{
    keyboardType = keyboardType.toLower();
    keyboardType[0] = keyboardType[0].toUpper();
    if(keyboardType == "Mechanical") return KeyboardType::Mechanical;
    else if(keyboardType == "Membrane") return KeyboardType::Membrane;
    else if(keyboardType == "Hybrid") return KeyboardType::Hybrid;
    else if(keyboardType == "Optical") return KeyboardType::Optical;
    else return KeyboardType::Other;
}
