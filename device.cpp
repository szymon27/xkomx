#include "device.h"

int Device::id() const
{
    return m_id;
}

void Device::setId(int id)
{
    m_id = id;
}

DeviceType Device::deviceType() const
{
    return m_deviceType;
}

void Device::setDeviceType(DeviceType deviceType)
{
    m_deviceType = deviceType;
}

const QString Device::producer() const
{
    return m_producer;
}

void Device::setProducer(QString producer)
{
    m_producer = producer;
}

const QString Device::model() const
{
    return m_model;
}

void Device::setModel(QString model)
{
    m_model = model;
}

int Device::count() const
{
    return m_count;
}

void Device::setCount(int count)
{
    m_count = count;
}

double Device::price() const
{
    return m_price;
}

void Device::setPrice(double price)
{
    m_price = price;
}

const QImage Device::image() const
{
    return m_image;
}

void Device::setImage(QImage image)
{
    m_image = image;
}

ImageType Device::imageType() const
{
    return m_imageType;
}

void Device::setImageType(ImageType imageType)
{
    m_imageType = imageType;
}

QString Device::description()
{
    return QString("%1 \nProducer: %2\nModel: %3\n")
            .arg(deviceTypeToString(m_deviceType), m_producer, m_model);
}

Device::Device(int id, DeviceType deviceType, QString producer, QString model,
        int count, double price, QImage image, ImageType imageType)
    :m_id(id), m_deviceType(deviceType), m_producer(producer), m_model(model),
      m_count(count), m_price(price), m_image(image), m_imageType(imageType)
{}
