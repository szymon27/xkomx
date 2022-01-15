#include "dbmanager.h"

DbManager* DbManager::s_instance = nullptr;

DbManager::DbManager() {
    m_qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    m_qSqlDatabase.setDatabaseName("C:\\Users\\szymo\\Desktop\\pipao projekt\\xkomx.db");
    //m_qSqlDatabase.setDatabaseName("C:\\Users\\Max\\Desktop\\baza\\xkomx.db");
    //m_qSqlDatabase.setDatabaseName("C:\\Users\\szymo\\Desktop\\pipao_proj\\xkomx.db");
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

QVector<Device*> DbManager::devicesList() const {
    QVector<Device*> list;
    QSqlQuery query;
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
            case DeviceType::Monitor: list.append(new class::Monitor(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Computer: list.append(new class::Computer(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Mouse: list.append(new class::Mouse(id, deviceType, producer, model, count, price, image, imageType, description)); break;
            case DeviceType::Keyboard: list.append(new class::Keyboard(id, deviceType, producer, model, count, price, image, imageType, description)); break;
        }

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
            case DeviceType::Monitor: return new class::Monitor(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Computer: return new class::Computer(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Mouse: return new class::Mouse(id, deviceType, producer, model, count, price, image, imageType, description);
            case DeviceType::Keyboard: return new class::Keyboard(id, deviceType, producer, model, count, price, image, imageType, description);
        }
    }
    return device;
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
                    query.prepare("INSERT INTO order_details VALUES(:order_id, :device_id, :device_count, :device_price);");
                    query.bindValue(":order_id", QVariant(lastId + 1));
                    query.bindValue(":device_id", QVariant(list[i].device->id()));
                    query.bindValue(":device_count", QVariant(list[i].count));
                    query.bindValue(":device_price", QVariant(list[i].device->price()));
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
