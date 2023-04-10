#pragma once
#include <iostream>
#include <cstring>
#include "UserLinkedList.h"
#include "User.h"
using namespace std;
#ifndef USERS_H
#define USERS_H
#endif

class Users
{
private:
	UserLinkedList users;
public:
	Users();
	Users(UserLinkedList users);
	Users(Users& users);
	void addUser(User u);
	UserLinkedList searchByName(string n); //all of the ones with vectors will be replaced by linked lists later
	UserLinkedList searchByAddress(string a);
	UserLinkedList searchByEmail(string e);
	UserLinkedList searchByPhoneNumber(string pn);
	UserLinkedList searchByKeyword(string n);
	void printUserInfo(User u);
	//void registerUser();
	
};

