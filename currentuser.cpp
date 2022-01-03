#include "currentuser.h"

CurrentUser* CurrentUser::s_instance = nullptr;

CurrentUser::CurrentUser()
{
    m_user = User();
}

CurrentUser::~CurrentUser()
{
    if(s_instance != nullptr)
        delete s_instance;
}

CurrentUser *CurrentUser::getInstance()
{
    if(s_instance == nullptr)
        s_instance = new CurrentUser();
    return s_instance;
}

void CurrentUser::setUser(User user)
{
    m_user = user;
}

User CurrentUser::getUser() const
{
    return m_user;
}
