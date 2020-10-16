#ifndef GECHATUSER_H_
#define GECHATUSER_H_
#include "customset.h"
#include <string>
#include <memory>
using namespace std;

class GechatUser
{
public:
	// Assume using namespace std;
	GechatUser();	
	GechatUser(const string username);
	GechatUser(const GechatUser& other);
	~GechatUser();
	
	const int numFriends() const;
	void setUsername(const string username);
	bool haveFriend(const shared_ptr<GechatUser> user) const; // return true if user is a friend to *this.
	bool addFriend(shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
	bool singleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool singleDelete(const string username); // return false only if username not found in friends.
	bool doubleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool doubleDelete(const string username); // return false only if username not found in friends.
	friend ostream& operator << (ostream& output, const GechatUser& fri);
	friend const bool operator < (const GechatUser& front, const GechatUser& back);
	friend const bool operator == (const GechatUser& front, const GechatUser& back);
private:
    string m_username;
    vector<shared_ptr<GechatUser>> m_friends;
};
#endif
