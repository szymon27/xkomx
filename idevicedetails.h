#ifndef IDEVICEDETAILS_H
#define IDEVICEDETAILS_H

#include <QString>

class IDeviceDetails
{
public:
    IDeviceDetails();
    ~IDeviceDetails();
    virtual QString GetDeviceDescription() = 0;
};

#endif // IDEVICEDETAILS_H
