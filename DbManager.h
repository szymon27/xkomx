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
#include "sorting.h"
#include <QSql>
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
    QVector<User> usersList() const;
    bool changeUserType(int id, int newType)const;
    QVector<Order> Orders() const;
    QVector<OrderDetails> orderDevices(int) const;
    Device *getDeviceById(int id);
    bool addNewDevice(DeviceType deviceType, QString producer, QString model, QString description, int count, double price, QByteArray image, ImageType imageType);
    bool editDevice(int id, DeviceType deviceType, QString producer, QString model, QString description, int count, double price, QByteArray image, ImageType imageType);
    bool newPassword(QString newpass);
    bool changeUserDetails(QString name, QString surname, QString city, QString postcode, QString address, QString country);
    QList<QString> getProducers();

    QVector<Device*> filterProducer(QString producer);
    QVector<Device*> filterDeviceType(DeviceType deviceType);
    QVector<Device*> sorted(Sorting sorting);
    QVector<Device*> search(QString search);

    bool removeById(int id);

    bool order(QString username, QString password);
};

#endif // DBMANAGER_H
