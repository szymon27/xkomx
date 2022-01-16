#ifndef ORDER_H
#define ORDER_H

#include <QDate>

class Order
{
private:
    int m_id;
    QDate m_orderDate;
    double m_totalCost;
public:
    Order(int id,  QDate date, double cost);
    int id() const;
    void setId(int newId);
    const QDate &orderDate() const;
    void setOrderDate(const QDate &newOrderDate);
    double totalCost() const;
    void setTotalCost(double newTotalCost);
};

#endif // ORDER_H
