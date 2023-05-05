//Made by Alanna Siebers
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
	int totalUsers = 0;
public:
	UserLinkedList() { head = NULL; }
	~UserLinkedList() {}

	//Add, Remove, and Get Functions
	void addUser(User u);
	void removeUser(User u);
	User getUserAt(int index);
	User getUser(int instID);

	//Print Functions
	void printUserAt(int index);
	void printAllUsers();

	//Search Functions
	UserLinkedList searchByName(string n);
	UserLinkedList searchByAddress(string a);
	UserLinkedList searchByEmail(string e);
	UserLinkedList searchByPhoneNumber(string pn);
	UserLinkedList searchByKeyword(string key);

	//Other Functions
	bool isValidLogin(int, string);
	int generateLibraryID();
	bool isLibraryIDUsed(int);
	UserNode* getHead() { return head;}
	int getTotalUsers() { return totalUsers; }
};

#endif