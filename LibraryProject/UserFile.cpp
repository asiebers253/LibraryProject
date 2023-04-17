#include "UserFile.h"
#include "UserLinkedList.h"
#include "Users.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable : 4996) //lets strtok be used

//Ask teacher for advice on this...

UserLinkedList UserFile::readFile() {
	UserLinkedList users;
	/*
	User u;
	u.setIsGuest(false);
	ifstream f;
	string str;
	string info;
	int counter = 1;
	char* c = new char;
	const char s[2] = ",";

	f.open("ListOfUsers.txt");
	if (!f.is_open()) {
		cout << "Could not open ListOfUsers.txt" << endl;
		return users;
	} 

	int numInfo;

	//ASK TEACHER ABOUT READING STUFF IN

	while (!f.eof()) {
		//get user information from the file
		getline(f, str);
		strcpy(c, str.c_str());
		
		char* sPtr = strtok(c, s);
		//cout << c;
		//put that user information into a user object
		//sPtr = strtok(c, s);
		//cout << sPtr;
		while (sPtr != NULL) {
			//info = sPtr;
			numInfo = atoi(sPtr);
			cout << numInfo << endl;
			/*
			//cout << sPtr;
			switch (counter) {
			case 1:
				u.setFirstName(info);
				break;
			case 2:
				u.setLastName(info);
				break;
			case 3:
				u.setAddress(info);
				break;
			case 4:
				u.setEmail(info);
				break;
			case 5:
				u.setPhoneNumber(info);
				break;
			case 6:
				u.setInstructionID(numInfo);
				cout << u.getInstructionID();
				break;
			case 7:
				u.setLibraryID(numInfo);
				break;
			case 8:
				if (info == "yes") {
					u.setIsAdmin(true);
				}
				break;
			case 9:
				if (info == "yes") {
					u.setIsDonor(true);
				}
				break;
			//add another case for borrowed books?
			}
			counter++;
			sPtr = strtok(NULL, s);
		}

		//add the user object to the linked list
		//u.printUserInfo();
		//users.addUser(u);
	}*/
	return users;
}

//make multiple files



void UserFile::writeFile(Users users) {
	Users usersInFile;
	fstream fstr;

	fstr.open("ListOfUsers.txt", ios::out);
	if (!fstr.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//int index;

	

}