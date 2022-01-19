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

QVector<CartElement> Cart::cartList() const
{
    return m_cartList;
}

void Cart::addDevice(Device *device)
{
    for(int i = 0; i < m_cartList.size(); i++) {
        if(m_cartList.at(i).device->id() == device->id()) {
            m_cartList[i].count++;
            return;
        }
    }
    m_cartList.append(CartElement(device, 1));
}

double Cart::sum() const
{
    double sum = 0;
    for(int i = 0; i < m_cartList.size(); i++)
        sum += (m_cartList.at(i).count * m_cartList.at(i).device->price());
    return sum;
}

void Cart::setCountOfCartElement(int id, int count)
{
    for(int i = 0; i < m_cartList.size(); i++) {
        if(m_cartList[i].device->id() == id)
           m_cartList[i].count = count;
    }
}

void Cart::removeCartElementById(int id)
{
    for(int i = 0; i < m_cartList.size(); i++) {
        if(m_cartList[i].device->id() == id) {
            m_cartList.removeAt(i);
            return;
        }
    }
}

void Cart::clearCartList()
{
    while(m_cartList.size() > 0)
        m_cartList.removeAt(0);
}

bool Cart::checkCart()
{
    for(int i = 0; i < m_cartList.size(); i++) {
        m_cartList[i].device = DbManager::instance()->getDeviceById(m_cartList[i].device->id());
        if(m_cartList[i].device->count() < m_cartList[i].count)
            return false;
    }
    return true;
}

