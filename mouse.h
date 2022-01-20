#ifndef MOUSE_H
#define MOUSE_H

#include "device.h"

class Mouse : public Device
{
protected:
    bool m_wireless;
    int m_keys;
    int m_dpi;
public:
    Mouse(int id, DeviceType deviceType, QString producer, QString model,
          int count, double price, QImage image, ImageType imageType,
          QString description);
    ~Mouse(){qDebug() << "inhe";};
    virtual QString description() override;
    bool wireless() const;
    void setWireless(bool newWireless);
    int keys() const;
    void setKeys(int newKeys);
    int dpi() const;
    void setDpi(int newDpi);
};

#endif // MOUSE_H
