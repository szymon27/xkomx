#ifndef KEYBOARDTYPE_H
#define KEYBOARDTYPE_H
#include <QString>

enum KeyboardType {
    Mechanical = 1,
    Membrane = 2,
    Hybrid = 3,
    Optical = 4,
    Other = 5
};

QString keyboardTypeToString(KeyboardType keyboardType);
KeyboardType stringToKeyboardType(QString keyboardType);

#endif // KEYBOARDTYPE_H
