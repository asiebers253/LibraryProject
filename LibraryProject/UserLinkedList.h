#pragma once
#ifndef UserLinkedList_H
#define UserLinkedList_H

#include <iostream>
#include "UserNode.h"
#include "User.h"
using namespace std;

class UserLinkedList {
private:
	UserNode* head;
	void searchBy(string str);
public:
	UserLinkedList() { head = NULL; }
	~UserLinkedList() {}

	//Finding and Modifying Users
	void registerUser(string, string, string, string, string, string, int, bool);
	void addUser(User u);
	void removeUser(User u);
	User getUserAt(int index);

	//Print functions
	void printUserAt(int index);
	void printAllUsers();

	//Search functions
	UserLinkedList searchByName(string n);
	UserLinkedList searchByAddress(string a);
	UserLinkedList searchByEmail(string e);
	UserLinkedList searchByPhoneNumber(string pn);
	UserLinkedList searchByKeyword(string key);

	//Other
	bool isValidLogin(int, string);
	int generateLibraryID();
	bool isLibraryIDUsed(int);
	UserNode* getHead() { return head;}
	void test();
};

#endif