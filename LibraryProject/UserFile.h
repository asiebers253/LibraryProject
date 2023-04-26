#pragma once
#ifndef Userfile_H
#define Userfile_H

#include <vector>
#include "UserLinkedList.h"
#include "Books.h"

class UserFile {
private:
	UserLinkedList readUserFile();
	UserLinkedList readBorrowedBookIDsFile(UserLinkedList users);
	UserLinkedList readBookSample(UserLinkedList users);
	void storeUsers(UserLinkedList users);
	void storeBookIDs(UserLinkedList users);
	int strToInt(string str);
public:
	UserLinkedList loadUsers();
	void saveUsers(UserLinkedList users);
};

#endif

//store information constantly as you add the information!
//don't need to make a new class for rewriting individual changes
//but adding a user could user an append funciton