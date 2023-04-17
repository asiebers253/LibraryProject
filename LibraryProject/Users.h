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
	void removeUser(User u);
	User getUserAt(int index);
	UserLinkedList searchByName(string n); 
	UserLinkedList searchByAddress(string a);
	UserLinkedList searchByEmail(string e);
	UserLinkedList searchByPhoneNumber(string pn);
	UserLinkedList searchByKeyword(string n);
	void printUserInfo(User u);
	void printAllUsers();
	void registerUser(string, string, string, string, string, string, int);
	bool createLibraryID(int lID);
};

