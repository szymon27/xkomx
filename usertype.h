#ifndef USERTYPE_H
#define USERTYPE_H

#include <QString>

enum UserType {
    Guest = 1,
    Customer = 2,
    Employee = 3,
    Manager = 4
};
QString userTypeToString(UserType userType);
#endif // USERTYPE_H
