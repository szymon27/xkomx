#ifndef CART_H
#define CART_H
#include <device.h>
#include "dbmanager.h"

struct CartElement {
    Device* device;
    int count;
    CartElement(Device* d, int c) {
        device = d;
        count = c;
    }
};

class Cart
{
private:
    QVector<CartElement> m_cartList;
protected:
    Cart();
    ~Cart();
    static Cart* s_instance;
public:
    Cart(Cart&) = delete;
    Cart operator=(Cart&) = delete;
    static Cart* instance();
    QVector<CartElement> cartList() const;
    void addDevice(Device* device);
    void removeDevice(Device* device);
    double sum() const;
    void setCountOfCartElement(int id, int count);
    void removeCartElementById(int id);
    void clearCartList();
    bool checkCart();
};

#endif // CART_H
