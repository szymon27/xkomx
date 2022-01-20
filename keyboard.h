#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "device.h"
#include "keyboardtype.h"

class Keyboard : public Device
{
protected:
    bool m_wireless;
    KeyboardType m_keyboardType;
    bool m_lighting;
    bool m_numpad;
public:
    Keyboard(int id, DeviceType deviceType, QString producer, QString model,
             int count, double price, QImage image, ImageType imageType,
             QString description);
    ~Keyboard(){};
    virtual QString description() override;
    bool wireless() const;
    void setWireless(bool newWireless);
    KeyboardType keyboardType() const;
    void setKeyboardType(KeyboardType newKeyboardType);
    bool lighting() const;
    void setLighting(bool newLighting);
    bool numpad() const;
    void setNumpad(bool newNumpad);
};

#endif // KEYBOARD_H
