#ifndef NEWUSER_H
#define NEWUSER_H

#include <QString>

struct NewUser {
    QString username;
    QString password;
    QString name;
    QString surname;
    QString address;
    QString postCode;
    QString city;
    QString country;
};

#endif // NEWUSER_H
