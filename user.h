#ifndef USER_H
#define USER_H

#include "usertype.h"
#include <QString>

class User
{
private:
    int m_id;
    UserType m_userType;
    QString m_username;
    QString m_password;
    QString m_name;
    QString m_surname;
    QString m_address;
    QString m_postCode;
    QString m_city;
    QString m_country;

public:
    User();
    User(int id, UserType userType, QString username, QString password, QString name,
         QString surname, QString address, QString postCode, QString city, QString country);

    int getId() const {return m_id;}
    QString getUsername() const {return m_username;}
    UserType getUserType() const {return m_userType;}
    const QString &name() const;
    const QString &surname() const;
    const QString &address() const;
    const QString &postCode() const;
    const QString &city() const;
    const QString &country() const;
};

#endif // USER_H
