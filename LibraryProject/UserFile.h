#pragma once
#ifndef Userfile_H
#define Userfile_H
#endif
#include "UserLinkedList.h"
#include "Books.h"
#include <vector>

//more will be added to this later

class UserFile
{
public:
	UserLinkedList loadUsers();
	UserLinkedList readUserFile();
	void storeUsers(UserLinkedList users);
	void storeBookIDs(UserLinkedList users);
	void readBorrowedBooks();
	void saveUsers(UserLinkedList users);
};

