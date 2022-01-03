#include "dbmanager.h"

DbManager* DbManager::s_instance = nullptr;

DbManager::DbManager() {
    m_qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    m_qSqlDatabase.setDatabaseName("C:\\Users\\szymo\\Desktop\\xkomx\\xkomx.db");
    m_qSqlDatabase.open();
}

DbManager::~DbManager() {
    if(m_qSqlDatabase.isOpen())
        m_qSqlDatabase.close();
    delete s_instance;
}

DbManager* DbManager::getInstance() {
    if(s_instance == nullptr)
        s_instance = new DbManager();
    return s_instance;
}

User DbManager::signIn(QString username, QString password) {
    User user = User();

    QSqlQuery query;
    //id, user_type_id, username, password, name, surname, address, post_code, city, country
    query.prepare("SELECT * FROM users WHERE username LIKE :username AND password LIKE :password;");
    query.bindValue(":username", QVariant(username));
    query.bindValue(":password", QVariant(password));

    if(query.exec() && query.next()) {
        int id = query.value(0).toInt();
        UserType userType = (UserType)query.value(1).toInt();
        QString username = query.value(2).toString();
        QString password = query.value(3).toString();
        QString name = query.value(4).toString();
        QString surname = query.value(5).toString();
        QString address = query.value(6).toString();
        QString postCode = query.value(7).toString();
        QString city = query.value(8).toString();
        QString country = query.value(9).toString();
        user = User(id, userType, username, password, name,
                    surname, address, postCode, city, country);
    }

    return user;
}

bool DbManager::userExists(QString username) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username LIKE :username;");
    query.bindValue(":username", QVariant(username));
    bool exists = true; //domyslnie uzytkownik istnieje

    if(query.exec() && query.next()) {
        int count = query.value(0).toInt();
        exists = (count == 0) ? false : true;
    }

    return exists;
}

bool DbManager::signUp(NewUser newUser) {
    if(userExists(newUser.username))
        return false;

    QSqlQuery query;
    query.prepare("INSERT INTO users(username, password, name, surname, address, post_code, city, country) VALUES(:username, :password, :name, :surname, :address, :postCode, :city, :country);");
    query.bindValue(":username", QVariant(newUser.username));
    query.bindValue(":password", QVariant(newUser.password));
    query.bindValue(":name", QVariant(newUser.name));
    query.bindValue(":surname", QVariant(newUser.surname));
    query.bindValue(":address", QVariant(newUser.address));
    query.bindValue(":postCode", QVariant(newUser.postCode));
    query.bindValue(":city", QVariant(newUser.city));
    query.bindValue(":country", QVariant(newUser.country));

    return query.exec();
}