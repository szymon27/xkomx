#include "mouse.h"

Mouse::Mouse(int id, DeviceType deviceType, QString producer, QString model, int count, double price, QImage image, ImageType imageType, QString description)
    :   Device(id, deviceType, producer, model, count, price, image, imageType)
{
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(description.toUtf8());
    QJsonObject qJsonObject = qJsonDocument.object();
    m_wireless = qJsonObject.value("wireless").toBool();
    m_keys = qJsonObject.value("keys").toInt();
    m_dpi = qJsonObject.value("dpi").toInt();
}

bool Mouse::wireless() const
{
    return m_wireless;
}

void Mouse::setWireless(bool newWireless)
{
    m_wireless = newWireless;
}

int Mouse::keys() const
{
    return m_keys;
}

void Mouse::setKeys(int newKeys)
{
    m_keys = newKeys;
}

int Mouse::dpi() const
{
    return m_dpi;
}

void Mouse::setDpi(int newDpi)
{
    m_dpi = newDpi;
}

QString Mouse::description()
{
    return QString(Device::description()) + QString("wireless: %1\nkeys: %2\ndpi: %3")
            .arg((m_wireless) ? "yes" : "no", QString::number(m_keys), QString::number(m_dpi));
}
