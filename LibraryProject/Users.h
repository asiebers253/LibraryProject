#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "User.h"
using namespace std;
#ifndef USERS_H
#define USERS_H
#endif

class Users
{
private:
	vector<User> users;
public:
	Users();
	Users(vector<User> users);
	Users(Users& users);
	void addUser(User u);
	vector<User> searchByName(); //all of the ones with vectors will be replaced by linked lists later
	vector<User> searchByAddress();
	vector<User> searchByEmail();
	vector<User> searchByPhoneNumber();
	vector<User> searchByKeyword();
	void printSearchResults();
	void printUserInfo(User u);
	void printAllUsers(); //will be replaced later
	void registerUser();
	
};

