#ifndef COMPUTER_H
#define COMPUTER_H

#include "device.h"

class Computer : public Device
{
protected:
    QString m_processor;
    QString m_ram;
    QString m_graphicsCard;
    QString m_disc;
    QString m_powerSupply;
    QString m_system;

public:
    Computer(int id, DeviceType deviceType, QString producer, QString model,
            int count, double price, QImage image, ImageType imageType,
            QString description);
    const QString &processor() const;
    void setProcessor(const QString &newProcessor);
    const QString &ram() const;
    void setRam(const QString &newRam);
    const QString &graphicsCard() const;
    void setGraphicsCard(const QString &newGraphicsCard);
    const QString &disc() const;
    void setDisc(const QString &newDisc);
    const QString &powerSupply() const;
    void setPowerSupply(const QString &newPowerSupply);
    virtual QString description() override;
};

#endif // COMPUTER_H
