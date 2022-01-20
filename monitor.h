#ifndef MONITOR_H
#define MONITOR_H

#include "device.h"
#include "displaytype.h"

class Monitor : public Device
{
protected:
    int m_refreshRate;
    double m_screenSize;
    QString m_resolution;
    DisplayType m_displayType;

public:
    Monitor(int id, DeviceType deviceType, QString producer, QString model,
            int count, double price, QImage image, ImageType imageType,
            QString description);
    ~Monitor(){qDebug() << "inhe";};
    int refreshRate() const;
    void setRefreshRate(int newRefreshRate);
    double screenSize() const;
    void setScreenSize(double newScreenSize);
    const QString &resolution() const;
    void setResolution(const QString &newResolution);
    DisplayType displayType() const;
    void setDisplayType(DisplayType newDisplayType);
    virtual QString description() override;
};

#endif // MONITOR_H
