#include "device.h"

int Device::id() const
{
    return m_id;
}

void Device::setId(int newId)
{
    m_id = newId;
}

DeviceType Device::deviceType() const
{
    return m_deviceType;
}

void Device::setDeviceType(DeviceType newDeviceType)
{
    m_deviceType = newDeviceType;
}

const QString &Device::producer() const
{
    return m_producer;
}

void Device::setProducer(const QString &newProducer)
{
    m_producer = newProducer;
}

const QString &Device::model() const
{
    return m_model;
}

void Device::setModel(const QString &newModel)
{
    m_model = newModel;
}

int Device::count() const
{
    return m_count;
}

void Device::setCount(int newCount)
{
    m_count = newCount;
}

double Device::price() const
{
    return m_price;
}

void Device::setPrice(double newPrice)
{
    m_price = newPrice;
}

const QImage &Device::image() const
{
    return m_image;
}

void Device::setImage(const QImage &newImage)
{
    m_image = newImage;
}

ImageType Device::imageType() const
{
    return m_imageType;
}

void Device::setImageType(ImageType newImageType)
{
    m_imageType = newImageType;
}

Device::Device(int id, DeviceType deviceType, QString producer, QString model,
        int count, double price, QImage image, ImageType imageType)
    :m_id(id), m_deviceType(deviceType), m_producer(producer), m_model(model),
      m_count(count), m_price(price), m_image(image), m_imageType(imageType)
{}
