#pragma once

#include<vector>
#include <string>
#include "Post.hpp"
#include "Network.hpp"

class Account
{
private:
	std::string username;
	std::string password;
	std::vector<Post> Post_obj;
    std::vector<std::string>following;
    Network<Account> * network;
public:
	Account();
	Account(std::string, std::string);
	void setUsername(std::string);
	std::string getUsername()const;
	void setPassword(std::string);
	std::string getPassword()const;
	bool addPost(std::string,std::string);
	void viewPosts()const;

    Network<Account> * getNetwork()const;
    void setNetwork(Network<Account> * );

    bool followAccount(const std::string&);
    std::vector<std::string> & viewFollowing();
};
