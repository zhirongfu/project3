#pragma once
#ifndef POST_H
#define POST_H
class Post
{
private:
	std::string post_title;
	std::string post_body;
	std::string user_name;
	time_t time_stamp_;
public:
	Post();
	Post(std::string, std::string,std::string);
	void setTitle(std::string);
	std::string getTitle()const;
	void setBody(std::string);
	std::string getBody()const;
	void setUsername(std::string);
	std::string getUsername()const;
	void setTimestamp(time_t);
	void getTimeStamp();
	void displayPost()const;

};
#endif 
