#pragma once
#ifndef POST_H
#define POST_H
#include "Account.hpp"
class Post //post class
{
private: //private members
	std::string post_title;
	std::string post_body;
	std::string user_name;
	time_t time_stamp_;
public: //public memebers
	Post();
	Post(std::string title, std::string body, std:: string username);
	void setTitle(const std::string title); //setter	
	std::string getTitle()const; //getter
	void setBody(const std::string body); //setter
	std::string getBody()const; //getter
	void setUsername(std::string username);
	std::string getUsername()const;
	void setTimestamp(time_t);
	void getTimeStamp(); //getter
	void displayPost();

};
#endif 
