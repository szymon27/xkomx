#include "order.h"

int Order::id() const
{
    return m_id;
}

void Order::setId(int newId)
{
    m_id = newId;
}

const QDate &Order::orderDate() const
{
    return m_orderDate;
}

void Order::setOrderDate(const QDate &newOrderDate)
{
    m_orderDate = newOrderDate;
}

double Order::totalCost() const
{
    return m_totalCost;
}

void Order::setTotalCost(double newTotalCost)
{
    m_totalCost = newTotalCost;
}

Order::Order(int id, QDate date, double cost)
    : m_id(id),
      m_orderDate(date),
      m_totalCost(cost)
{

}
