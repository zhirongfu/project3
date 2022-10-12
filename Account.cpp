#include <iostream>
#include <time.h>
#include "Post.hpp"
#include "Account.hpp"
using namespace std;
Account::Account()
{
    username = " ";
    password = " ";
    network = nullptr;
}
Account::Account(string tmpusername, string tmppassword)
{
    network = nullptr;
    username = tmpusername;
    password = tmppassword;
}
void Account::setUsername(string tmpusername)
{
    username = tmpusername;
}
string Account::getUsername() const
{
    return username;
}
void Account::setPassword(string tmppassword)
{
    password = tmppassword;
}
string Account::getPassword() const
{
    return password;
}
bool Account::addPost(string title, string body)
{
    Post obj;
    if(title.empty() || body.empty() || network==nullptr)
        return false;

    obj.setTitle(title);
    obj.setBody(body);
    obj.setUsername(username);
    Post_obj.push_back(obj);

    network->addToFeed(obj);
    return true;
}
void display(Post obj)
{
    cout << "{" << obj.getTitle() << "}"
         << "posted at {";
    obj.getTimeStamp();
    cout << " }" << endl;
    cout << "{" << obj.getBody() << "}" << endl;
}
void Account::viewPosts() const
{
    for (size_t i = 0; i < Post_obj.size(); ++i)
    {
        Post obj = Post_obj.at(i);
        display(obj);
        cout << endl;
    }
}

Network<Account> *Account::getNetwork() const
{
    return network;
}
void Account::setNetwork(Network<Account> *net)
{
    network = net;
}

bool Account::followAccount(const std::string &to_follow)
{
    if(network==nullptr)
        return false;
    
    for (string &f : following)
        if (f == to_follow)
            return false;

    following.push_back(to_follow);
    return true;
}

std::vector<std::string> &Account::viewFollowing()
{
    return following;
}
