#include "keyboard.h"

Keyboard::Keyboard(int id, DeviceType deviceType, QString producer, QString model, int count, double price, QImage image, ImageType imageType, QString description)
    :   Device(id, deviceType, producer, model, count, price, image, imageType)
{
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(description.toUtf8());
    QJsonObject qJsonObject = qJsonDocument.object();
    m_wireless = qJsonObject.value("wireless").toBool();
    m_keyboardType = stringToKeyboardType(qJsonObject.value("keyboard type").toString());
    m_lighting= qJsonObject.value("lighting").toBool();
    m_numpad = qJsonObject.value("numpad").toBool();
}

bool Keyboard::wireless() const
{
    return m_wireless;
}

void Keyboard::setWireless(bool newWireless)
{
    m_wireless = newWireless;
}

KeyboardType Keyboard::keyboardType() const
{
    return m_keyboardType;
}

void Keyboard::setKeyboardType(KeyboardType newKeyboardType)
{
    m_keyboardType = newKeyboardType;
}

bool Keyboard::lighting() const
{
    return m_lighting;
}

void Keyboard::setLighting(bool newLighting)
{
    m_lighting = newLighting;
}

bool Keyboard::numpad() const
{
    return m_numpad;
}

void Keyboard::setNumpad(bool newNumpad)
{
    m_numpad = newNumpad;
}

QString Keyboard::description()
{
    return QString(Device::description()) + QString("wireless: %1\nswitches: %2\nlighting: %3\nnumpad: %4")
            .arg((m_wireless) ? "yes" : "no", keyboardTypeToString(m_keyboardType), (m_lighting) ? "yes" : "no", (m_numpad) ? "yes" : "no");
}
