#include "displaytype.h"

QString displayTypeToString(DisplayType displayType)
{
    switch(displayType) {
        case DisplayType::IPS: return "IPS";
        case DisplayType::LCD: return "LCD";
        case DisplayType::OLED: return "OLED";
        case DisplayType::TN: return "TN";
        case DisplayType::VA: return "VA";
        default: return "OTHER";
    }
}

DisplayType stringToDisplayType(QString displayType)
{
    displayType = displayType.toUpper();
    if(displayType == "IPS") return DisplayType::IPS;
    else if(displayType == "LCD") return DisplayType::LCD;
    else if(displayType == "OLED") return DisplayType::OLED;
    else if(displayType == "TN") return DisplayType::TN;
    else if(displayType == "VA") return DisplayType::VA;
    else return DisplayType::OTHER;
}
