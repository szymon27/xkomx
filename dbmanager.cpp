#include "dbmanager.h"
#include <QSqlError>

DbManager* DbManager::s_instance = nullptr;

DbManager::DbManager() {
    m_qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    //m_qSqlDatabase.setDatabaseName("C:\\Users\\szymo\\Desktop\\pipao projekt\\xkomx.db");
    //m_qSqlDatabase.setDatabaseName("C:\\Users\\Max\\Desktop\\baza\\xkomx.db");
    //m_qSqlDatabase.setDatabaseName("C:\\Users\\szymo\\Desktop\\pipao_proj\\xkomx.db");
    m_qSqlDatabase.setDatabaseName("A:\\Projekty programowanie\\xcomx baza\\xkomx.db");

    m_qSqlDatabase.open();
}

DbManager::~DbManager() {
    if(m_qSqlDatabase.isOpen())
        m_qSqlDatabase.close();
    delete s_instance;
}

DbManager* DbManager::instance() {
    if(s_instance == nullptr)
        s_instance = new DbManager();
    return s_instance;
}

User DbManager::signIn(QString username, QString password) {
    User user = User();

    QSqlQuery query;
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

QVector<Device*> DbManager::devicesList(){
    QSqlQuery query;
    QVector<Device*> list;
    query.prepare("SELECT * FROM devices;");
    query.exec();
    while(query.next()) {
        int id = query.value(0).toInt();
        DeviceType deviceType = (DeviceType)query.value(1).toInt();
        QString producer = query.value(2).toString();
        QString model = query.value(3).toString();
        QString description = query.value(4).toString();
        int count = query.value(5).toInt();
        double price = query.value(6).toDouble();
        QByteArray byteArray = query.value(7).toByteArray();
        ImageType imageType = (ImageType)query.value(8).toInt();
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::ReadOnly);
        QImageReader imageReader(&buffer, imageTypeToString(imageType).toStdString().c_str());
        QImage image = imageReader.read();

        switch(deviceType) {
        case Unknown:
            break;
        case DeviceType::Monitor: list.append(new class::Monitor(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Computer: list.append(new class::Computer(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Mouse: list.append(new class::Mouse(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Keyboard: list.append(new class::Keyboard(id, deviceType, producer, model, count, price, image, imageType, description)); break;
        }

    }
    return list;
}

QVector<User> DbManager::usersList() const
{
    QVector<User> list;
    QSqlQuery query;
    query.prepare("SELECT * FROM users;");
    query.exec();
    while(query.next()) {
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
        list.append(User(id, userType, username, password, name,
                    surname, address, postCode, city, country));
    }
    return list;
}

bool DbManager::changeUserType(int id, int newType) const
{
    QSqlQuery query;
    query.prepare("UPDATE users SET user_type_id=:newType WHERE id=:uid;");
    query.bindValue(":newType", QVariant(newType));
    query.bindValue(":uid", QVariant(id));
    return query.exec();
}

QVector<Order> DbManager::Orders() const
{
    QVector<Order> list;
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE user_id = :user_id;");
    query.bindValue(":user_id", QVariant(CurrentUser::instance()->user().id()));
    query.exec();
    while(query.next()){
        int id = query.value(0).toInt();
        double totalCost = query.value(3).toDouble();
        QDate date = query.value(4).toDate();

        list.append(Order(id, date, totalCost));
    }
    return list;
}

QVector<OrderDetails> DbManager::orderDevices(int oid) const
{
    QVector<OrderDetails> list;
    QSqlQuery query;
    query.prepare("SELECT * FROM order_details WHERE order_id=:orderId;");
    query.bindValue(":orderId", QVariant(oid));
    query.exec();
    while(query.next()){
        int count = query.value(1).toInt();
        double price = query.value(2).toDouble();
        QString model = query.value(3).toString();
        QString producer = query.value(4).toString();
        list.append(OrderDetails(count, price, model, producer));
    }
    return list;
}


Device *DbManager::getDeviceById(int id)
{
    Device* device = nullptr;
    QSqlQuery query;
    query.prepare("SELECT * FROM devices WHERE id=:id;");
    query.bindValue(":id", QVariant(id));
    query.exec();
    if(query.exec() && query.next()) {
        DeviceType deviceType = (DeviceType)query.value(1).toInt();
        QString producer = query.value(2).toString();
        QString model = query.value(3).toString();
        QString description = query.value(4).toString();
        int count = query.value(5).toInt();
        double price = query.value(6).toDouble();
        QByteArray byteArray = query.value(7).toByteArray();
        ImageType imageType = (ImageType)query.value(8).toInt();
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::ReadOnly);
        QImageReader imageReader(&buffer, imageTypeToString(imageType).toStdString().c_str());
        QImage image = imageReader.read();

        switch(deviceType) {
        case Unknown:
            break;
        case DeviceType::Monitor: return new class::Monitor(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Computer: return new class::Computer(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Mouse: return new class::Mouse(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Keyboard: return new class::Keyboard(id, deviceType, producer, model, count, price, image, imageType, description);
        }
    }
    return device;
}

bool DbManager::addNewDevice(DeviceType deviceType, QString producer, QString model, QString description, int count, double price, QByteArray file, ImageType imageType)
{
    QSqlQuery query;
    query.prepare("INSERT INTO devices (device_type_id, producer, model, description, count, price, photo, image_type_id) VALUES(:deviceType, :producer, :model, :description, :count, :price, :file, :imageType);");
    query.bindValue(":deviceType", QVariant((int)deviceType));
    query.bindValue(":producer", QVariant(producer));
    query.bindValue(":model", QVariant(model));
    query.bindValue(":description", QVariant(description));
    query.bindValue(":count", QVariant(count));
    query.bindValue(":price", QVariant(price));
    query.bindValue(":file", file, QSql::In | QSql::Binary);
    query.bindValue(":imageType", QVariant(int(imageType)));
    return query.exec();
}

bool DbManager::editDevice(int id, DeviceType deviceType, QString producer, QString model, QString description, int count, double price, QByteArray file, ImageType imageType){
    QSqlQuery query;
    query.prepare("UPDATE devices SET device_type_id=:deviceType, producer=:producer, model=:model, count=:count, price=:price, photo=:photo, image_type_id=:imageType, description=:description WHERE id=:id;");
    query.bindValue(":deviceType", QVariant((int)deviceType));
    query.bindValue(":producer", QVariant(producer));
    query.bindValue(":model", QVariant(model));
    query.bindValue(":count", QVariant(count));
    query.bindValue(":price", QVariant(price));
    query.bindValue(":photo", file, QSql::In | QSql::Binary);
    query.bindValue(":imageType", QVariant((int)imageType));
    query.bindValue(":description", QVariant(description));
    query.bindValue(":id", QVariant(id));
    return query.exec();
}

bool DbManager::newPassword(QString newpass)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET password =:newpass WHERE id=:uid;");
    query.bindValue(":newpass", QVariant(newpass));
    query.bindValue(":uid", QVariant(CurrentUser::instance()->user().id()));
    return query.exec();
}

bool DbManager::changeUserDetails(QString name, QString surname, QString city, QString postcode, QString address, QString country)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET name=:name, surname=:surname, city=:city, post_code=:postCode, address=:address, country=:country WHERE id=:uid;");
    query.bindValue(":name", QVariant(name));
    query.bindValue(":surname", QVariant(surname));
    query.bindValue(":address", QVariant(address));
    query.bindValue(":postCode", QVariant(postcode));
    query.bindValue(":city", QVariant(city));
    query.bindValue(":country", QVariant(country));
    query.bindValue(":uid", QVariant(CurrentUser::instance()->user().id()));

    return query.exec();
}

QList<QString> DbManager::getProducers()
{
    QSqlQuery query;
    query.prepare("SELECT distinct(producer) FROM devices;");
    query.exec();
    QList<QString> list;
    while(query.next())
        list.append(query.value(0).toString());
    return list;
}

QVector<Device *> DbManager::filtredList(QString statement)
{
    QSqlQuery query;
    QVector<Device*> list;
    list.clear();
    query.prepare(statement);
    query.exec();
    while(query.next()) {
        int id = query.value(0).toInt();
        DeviceType deviceType = (DeviceType)query.value(1).toInt();
        QString producer = query.value(2).toString();
        QString model = query.value(3).toString();
        QString description = query.value(4).toString();
        int count = query.value(5).toInt();
        double price = query.value(6).toDouble();
        QByteArray byteArray = query.value(7).toByteArray();
        ImageType imageType = (ImageType)query.value(8).toInt();
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::ReadOnly);
        QImageReader imageReader(&buffer, imageTypeToString(imageType).toStdString().c_str());
        QImage image = imageReader.read();

        switch(deviceType) {
        case Unknown:
            break;
        case DeviceType::Monitor: list.append(new class::Monitor(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Computer: list.append(new class::Computer(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Mouse: list.append(new class::Mouse(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Keyboard: list.append(new class::Keyboard(id, deviceType, producer, model, count, price, image, imageType, description)); break;
        }

    }
    return list;
}

bool DbManager::removeById(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM devices WHERE id=:id");
    query.bindValue(":id", QVariant(id));
    return query.exec();
}

bool DbManager::order(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT id, balance FROM bank WHERE username LIKE :username AND password LIKE :password;");
    query.bindValue(":username", QVariant(username));
    query.bindValue(":password", QVariant(password));

    if(query.exec() && query.next()) {
        int bankId = query.value(0).toInt();
        double balance = query.value(1).toDouble();
        double dif = balance - Cart::instance()->sum();
        if(dif >= 0) {
            query.prepare("UPDATE bank SET balance=:dif WHERE id=:id;");
            query.bindValue(":dif", QVariant(dif));
            query.bindValue(":id", QVariant(bankId));
            query.exec();
            query.prepare("SELECT MAX(id) FROM orders;");
            if(query.exec() && query.next()) {
                int lastId = query.value(0).toInt();
                query.prepare("INSERT INTO orders VALUES(:id, :user_id, :bank_id, :price, :date);");
                query.bindValue(":id", QVariant(lastId + 1));
                query.bindValue(":user_id", QVariant(CurrentUser::instance()->user().id()));
                query.bindValue(":bank_id", QVariant(bankId));
                query.bindValue(":price", QVariant(Cart::instance()->sum()));
                query.bindValue(":date", QVariant(QDateTime::currentDateTime().date()));
                query.exec();
                QVector<CartElement> list = Cart::instance()->cartList();
                for(int i = 0; i < list.size(); i++) {
                    query.prepare("INSERT INTO order_details VALUES(:order_id, :device_count, :device_price, :model, :producer);");
                    query.bindValue(":order_id", QVariant(lastId + 1));
                    query.bindValue(":device_count", QVariant(list[i].count));
                    query.bindValue(":device_price", QVariant(list[i].device->price()));
                    query.bindValue(":model", QVariant(list[i].device->model()));
                    query.bindValue(":producer", QVariant(list[i].device->producer()));
                    query.exec();
                    query.prepare("UPDATE devices SET count=:count WHERE id=:device_id;");
                    query.bindValue(":count", QVariant(list[i].device->count() - list[i].count));
                    query.bindValue(":device_id", QVariant(list[i].device->id()));
                    query.exec();
                }
                return true;
            }
        }
    }
    return false;
}
