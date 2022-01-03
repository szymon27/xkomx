#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "user.h"
#include "newuser.h"

class DbManager
{
private:
    QSqlDatabase m_qSqlDatabase;
protected:
    DbManager();
    ~DbManager();
    static DbManager* s_instance;
public:
    DbManager(DbManager&) = delete;
    DbManager operator=(DbManager&) = delete;
    static DbManager* getInstance();

    User signIn(QString username, QString password);
    bool userExists(QString username);
    bool signUp(NewUser user);
};

#endif // DBMANAGER_H