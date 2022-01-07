#include "user.h"

const QString &User::name() const
{
    return m_name;
}

const QString &User::surname() const
{
    return m_surname;
}

const QString &User::address() const
{
    return m_address;
}

const QString &User::postCode() const
{
    return m_postCode;
}

const QString &User::city() const
{
    return m_city;
}

const QString &User::country() const
{
    return m_country;
}

void User::setId(int newId)
{
    m_id = newId;
}

void User::setUserType(UserType newUserType)
{
    m_userType = newUserType;
}

void User::setUsername(const QString &newUsername)
{
    m_username = newUsername;
}

void User::setPassword(const QString &newPassword)
{
    m_password = newPassword;
}

void User::setName(const QString &newName)
{
    m_name = newName;
}

void User::setSurname(const QString &newSurname)
{
    m_surname = newSurname;
}

void User::setAddress(const QString &newAddress)
{
    m_address = newAddress;
}

void User::setPostCode(const QString &newPostCode)
{
    m_postCode = newPostCode;
}

void User::setCity(const QString &newCity)
{
    m_city = newCity;
}

void User::setCountry(const QString &newCountry)
{
    m_country = newCountry;
}

User::User()
    :m_id(0), m_userType(UserType::Guest), m_username(""), m_password(""), m_name(""),
      m_surname(""), m_address(""), m_postCode(""), m_city(""), m_country("")
{}

User::User(int id, UserType userType, QString username, QString password, QString name,
           QString surname, QString address, QString postCode, QString city, QString country)
    :m_id(id), m_userType(userType), m_username(username), m_password(password), m_name(name),
      m_surname(surname), m_address(address), m_postCode(postCode), m_city(city), m_country(country)
{}
