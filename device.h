#ifndef DEVICE_H
#define DEVICE_H

#include "devicetype.h"
#include <QString>
#include <QImage>
#include "imagetype.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

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

public:
    Device(int id, DeviceType deviceType, QString producer, QString model,
           int count, double price, QImage image, ImageType imageType);
    int id() const;
    void setId(int newId);
    DeviceType deviceType() const;
    void setDeviceType(DeviceType newDeviceType);
    const QString &producer() const;
    void setProducer(const QString &newProducer);
    const QString &model() const;
    void setModel(const QString &newModel);
    int count() const;
    void setCount(int newCount);
    double price() const;
    void setPrice(double newPrice);
    const QImage &image() const;
    void setImage(const QImage &newImage);
    ImageType imageType() const;
    void setImageType(ImageType newImageType);
    virtual QString description() = 0;
};

#endif // DEVICE_H
