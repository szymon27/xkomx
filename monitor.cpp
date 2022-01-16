#include "monitor.h"

Monitor::Monitor(int id, DeviceType deviceType, QString producer, QString model, int count, double price, QImage image, ImageType imageType, QString description)
    :   Device(id, deviceType, producer, model, count, price, image, imageType)
{
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(description.toUtf8());
    QJsonObject qJsonObject = qJsonDocument.object();
    m_refreshRate = qJsonObject.value("refresh rate").toInt();
    m_screenSize = qJsonObject.value("screen size").toDouble();
    m_resolution = qJsonObject.value("resolution").toString();
    m_displayType = stringToDisplayType(qJsonObject.value("display type").toString());
}

int Monitor::refreshRate() const
{
    return m_refreshRate;
}

void Monitor::setRefreshRate(int newRefreshRate)
{
    m_refreshRate = newRefreshRate;
}

double Monitor::screenSize() const
{
    return m_screenSize;
}

void Monitor::setScreenSize(double newScreenSize)
{
    m_screenSize = newScreenSize;
}

const QString &Monitor::resolution() const
{
    return m_resolution;
}

void Monitor::setResolution(const QString &newResolution)
{
    m_resolution = newResolution;
}

DisplayType Monitor::displayType() const
{
    return m_displayType;
}

void Monitor::setDisplayType(DisplayType newDisplayType)
{
    m_displayType = newDisplayType;
}

QString Monitor::description()
{
    return QString(Device::description()) + QString("refresh rate: %1\nscreen size: %2\nresolution: %3\ndisplay type: %4")
            .arg(QString::number(m_refreshRate), QString::number(m_screenSize), m_resolution, displayTypeToString(m_displayType));
}
