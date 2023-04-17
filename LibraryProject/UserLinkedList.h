#pragma once
#include <iostream>
#include "UserNode.h"
#include "User.h"
using namespace std;
#ifndef UserLinkedList_H
#define UserLinkedList_H
#endif


class UserLinkedList {
private:
	UserNode* head;
	void searchBy(string str);
public:
	UserLinkedList() { head = NULL; }
	~UserLinkedList() {}
	void addNode(User u);
	void removeNode(User u);
	User getNodeAt(int index);
	UserLinkedList printAllUsers();
	UserLinkedList searchByName(string n);
	UserLinkedList searchByAddress(string a);
	UserLinkedList searchByEmail(string e);
	UserLinkedList searchByPhoneNumber(string pn);
	UserLinkedList searchByKeyword(string key);
};
