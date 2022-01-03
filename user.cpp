#include "user.h"

User::User()
    :m_id(0), m_userType(UserType::Guest), m_username(""), m_password(""), m_name(""),
      m_surname(""), m_address(""), m_postCode(""), m_city(""), m_country("")
{}

User::User(int id, UserType userType, QString username, QString password, QString name,
           QString surname, QString address, QString postCode, QString city, QString country)
    :m_id(id), m_userType(userType), m_username(username), m_password(password), m_name(name),
      m_surname(surname), m_address(address), m_postCode(postCode), m_city(city), m_country(country)
{}