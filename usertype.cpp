#include "usertype.h"

QString userTypeToString(UserType userType) {
    switch(userType){
        case UserType::Guest: return "Guest";
        case UserType::Customer: return "Customer";
        case UserType::Employee: return "Employee";
        case UserType::Manager: return "Manager";
    }
}
