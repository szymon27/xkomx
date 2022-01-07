#ifndef CURRENTUSER_H
#define CURRENTUSER_H
#include "user.h"

class CurrentUser {
private:
    User m_user;
protected:
    CurrentUser();
    ~CurrentUser();
    static CurrentUser* s_instance;
public:
    CurrentUser(CurrentUser&) = delete;
    CurrentUser operator=(CurrentUser&) = delete;
    static CurrentUser* instance();
    void setUser(User user);
    User user() const;
};

#endif // CURRENTUSER_H
