#include "cart.h"

Cart* Cart::s_instance = nullptr;

Cart::Cart() {

}

Cart::~Cart() {

}

Cart* Cart::instance() {
    if(s_instance == nullptr)
        s_instance = new Cart();
    return s_instance;
}

QVector<Device*> Cart::cartList() const
{
    return m_cartList;
}

void Cart::addDevice(Device *device)
{
    m_cartList.append(device);
}
