#ifndef CART_H
#define CART_H
#include <device.h>

class Cart
{
private:
    QVector<Device*> m_cartList;
protected:
    Cart();
    ~Cart();
    static Cart* s_instance;
public:
    Cart(Cart&) = delete;
    Cart operator=(Cart&) = delete;
    static Cart* instance();
    QVector<Device*> cartList() const;
    void addDevice(Device* device);
    void removeDevice(Device* device);
};

#endif // CART_H
