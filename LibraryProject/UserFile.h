#pragma once
#ifndef Userfile_H
#define Userfile_H
#endif
#include "Users.h"

//more will be added to this later

class UserFile
{
public:
	UserLinkedList readFile();
	void writeFile(Users users);
};

