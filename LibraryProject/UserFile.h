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
public:
	UserLinkedList loadUsers();
	void saveUsers(UserLinkedList users);
};

#endif