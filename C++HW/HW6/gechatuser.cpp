#include "gechatuser.h"

GechatUser::GechatUser()
{
}

GechatUser::GechatUser(const string username) : m_username(username)
{
}

GechatUser::GechatUser(const GechatUser& other) : m_username(other.m_username), m_friends(other.m_friends)
{
}

GechatUser::~GechatUser()
{
}

const int GechatUser::numFriends() const
{
    return m_friends.size();
}

void GechatUser::setUsername(const string username)
{
    m_username = username;
}

bool GechatUser::haveFriend(const shared_ptr<GechatUser> user) const
{
    if (count(m_friends.begin(), m_friends.end(), user))
    {
        return true;
    }
    return false;
}

bool GechatUser::addFriend(shared_ptr<GechatUser> user)
{
    if ((!this->haveFriend(user)) && (user))
    {
        m_friends.push_back(user);
        return true;
    }
    return false;
}

bool GechatUser::singleDelete(shared_ptr<GechatUser> user)
{
    vector<shared_ptr<GechatUser>>::iterator it = m_friends.begin();
    for (; it != m_friends.end(); it++)
    {
        if (*it == user)
        {
            m_friends.erase(it);
            return true;
        }   
    }
    return false;
}

bool GechatUser::singleDelete(const string username)
{
    vector<shared_ptr<GechatUser>>::iterator it = m_friends.begin();
    for (; it != m_friends.end(); it++)
    {
        if ((*it)->m_username == username)
        {
            m_friends.erase(it);
            return true;
        }   
    }
    return false;
}

bool GechatUser::doubleDelete(shared_ptr<GechatUser> user)
{
    return ((this->singleDelete(user)) && (user->singleDelete(this->m_username)));
}

bool GechatUser::doubleDelete(const string username)
{
    vector<shared_ptr<GechatUser>>::iterator it = m_friends.begin();
    for (; it != m_friends.end(); it++)
    {
        if ((*it)->m_username == username)
        {
            (*it)->singleDelete(m_username);
            this->singleDelete(username);
            return true;
        }
    }
    return false;
}


ostream& operator << (ostream& output, const GechatUser& fri)
{
    output<<fri.m_username<<" (friends: "<<fri.m_friends.size()<<')';
    return output;
}

const bool operator < (const GechatUser& front, const GechatUser& back)
{
    return front.m_username < back.m_username;
}

const bool operator == (const GechatUser& front, const GechatUser& back)
{
    return front.m_username == back.m_username;
}
