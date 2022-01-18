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

    const QString processor() const;
    void setProcessor(const QString processor);
    const QString ram() const;
    void setRam(const QString ram);
    const QString graphicsCard() const;
    void setGraphicsCard(const QString graphicsCard);
    const QString disc() const;
    void setDisc(const QString disc);
    const QString powerSupply() const;
    void setPowerSupply(const QString powerSupply);
    virtual QString description() override;
    const QString &system() const;
    void setSystem(const QString &newSystem);
};

#endif // COMPUTER_H
