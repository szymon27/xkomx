#include "user.h"

const QString User::name() const
{
    return m_name;
}

const QString User::surname() const
{
    return m_surname;
}

const QString User::address() const
{
    return m_address;
}

const QString User::postCode() const
{
    return m_postCode;
}

const QString User::city() const
{
    return m_city;
}

const QString User::country() const
{
    return m_country;
}

const QString User::password() const
{
    return m_password;
}

void User::setId(int id)
{
    m_id = id;
}

void User::setUserType(UserType userType)
{
    m_userType = userType;
}

void User::setUsername(const QString username)
{
    m_username = username;
}

void User::setPassword(const QString password)
{
    m_password = password;
}

void User::setName(const QString name)
{
    m_name = name;
}

void User::setSurname(const QString surname)
{
    m_surname = surname;
}

void User::setAddress(const QString address)
{
    m_address = address;
}

void User::setPostCode(const QString postCode)
{
    m_postCode = postCode;
}

void User::setCity(const QString city)
{
    m_city = city;
}

void User::setCountry(const QString country)
{
    m_country = country;
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

const QString User::username() const
{
    return m_username;
}

UserType User::userType() const
{
    return m_userType;
}

int User::id() const {
    return m_id;
}
