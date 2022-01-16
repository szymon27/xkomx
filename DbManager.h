#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "user.h"
#include "newuser.h"
#include <QVector>
#include "device.h"
#include <QBuffer>
#include <QImageReader>
#include <imagetype.h>
#include "monitor.h"
#include "computer.h"
#include "mouse.h"
#include "keyboard.h"
#include "cart.h"
#include "currentuser.h"
#include "order.h"
#include <QDateTime>

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
    static DbManager* instance();

    User signIn(QString username, QString password);
    bool userExists(QString username);
    bool signUp(NewUser user);

    QVector<Device*> devicesList() const;
    QVector<Order*> currentUserOrders()const;
    Device *getDeviceById(int id);

    bool order(QString username, QString password);
};

#endif // DBMANAGER_H
