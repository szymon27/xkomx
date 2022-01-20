#ifndef DEVICE_H
#define DEVICE_H

#include "devicetype.h"
#include <QString>
#include <QImage>
#include "imagetype.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

class Device {
protected:
    int m_id;
    DeviceType m_deviceType;
    QString m_producer;
    QString m_model;
    int m_count;
    double m_price;
    QImage m_image;
    ImageType m_imageType;

    Device(int id, DeviceType deviceType, QString producer, QString model,
           int count, double price, QImage image, ImageType imageType);
public:
    virtual ~Device(){qDebug() << "base";};
    int id() const;
    void setId(int id);
    DeviceType deviceType() const;
    void setDeviceType(DeviceType deviceType);
    const QString producer() const;
    void setProducer(const QString producer);
    const QString model() const;
    void setModel(const QString model);
    int count() const;
    void setCount(int count);
    double price() const;
    void setPrice(double price);
    const QImage image() const;
    void setImage(const QImage image);
    ImageType imageType() const;
    void setImageType(ImageType imageType);
    virtual QString description();
};

#endif // DEVICE_H
