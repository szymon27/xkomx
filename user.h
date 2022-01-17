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

    int id() const;
    const QString username() const;
    UserType userType() const;
    const QString name() const;
    const QString surname() const;
    const QString address() const;
    const QString postCode() const;
    const QString city() const;
    const QString country() const;
    const QString password() const;
    void setId(int id);
    void setUserType(UserType userType);
    void setUsername(QString username);
    void setPassword(QString password);
    void setName(QString name);
    void setSurname(QString surname);
    void setAddress(QString address);
    void setPostCode(QString postCode);
    void setCity(QString city);
    void setCountry(QString country);
};


#endif // USER_H
