#ifndef DEVICE_H
#define DEVICE_H

#include "devicetype.h"
#include <QString>
#include <QImage>
#include "imagetype.h"

class Device {
public:
    int m_id;
    DeviceType m_deviceType;
    QString m_producer;
    QString m_model;
    QString m_description;
    int m_count;
    double m_price;
    QImage m_image;
    ImageType m_imageType;
    Device(int id, DeviceType deviceType, QString producer, QString model,
           QString description, int count, double price, QImage image, ImageType imageType)
        :m_id(id), m_deviceType(deviceType), m_producer(producer), m_model(model),
          m_description(description), m_count(count), m_price(price), m_image(image), m_imageType(imageType)
    {}
    QString descriptionToString(){return m_description;};
};

#endif // DEVICE_H
