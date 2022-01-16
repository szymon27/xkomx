#ifndef ORDER_H
#define ORDER_H

#include <QDate>
#include <QString>

class Order
{
private:
    int m_id;
    QDate m_orderDate;
    double m_totalCost;

public:
    Order(int id, QDate date, double cost);
    int id() const;
    void setId(int newId);
    const QDate &orderDate() const;
    void setOrderDate(const QDate &newOrderDate);
    double totalCost() const;
    void setTotalCost(double newTotalCost);
};

struct OrderDetails{
    int count;
    double price;
    QString model;
    QString producer;
    OrderDetails(int c, double p, QString m, QString pr):
        count(c),
        price(p),
        model(m),
        producer(pr){}
};

#endif // ORDER_H
