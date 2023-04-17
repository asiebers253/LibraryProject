#include "Users.h"
#include <iostream>
#include <cstring>
#include "UserLinkedList.h"
#include "User.h"
#include "UserFile.h"
using namespace std;

//Default Constructor
Users::Users() {
	UserFile f;
	users = f.readFile();
}

//Parametric Constructor
Users::Users(UserLinkedList users) {
	this->users = users;
}

//Copy Constructor
Users::Users(Users& u) {
	this->users = u.users;
}

//Adds a user to the linked list
void Users::addUser(User u) {
	users.addNode(u);
}

//Accesses the searchByName function in the userLinkedList class
UserLinkedList Users::searchByName(string n) {
	return users.searchByName(n);
}

//Accesses the searchByAddress function in the userLinkedList class
UserLinkedList Users::searchByAddress(string a) {
	return users.searchByAddress(a);
}

//Accesses the searchByEmail function in the userLinkedList class
UserLinkedList Users::searchByEmail(string e) {
	return users.searchByEmail(e);
}

//Accesses the searchByPhoneNumber function in the userLinkedList class
UserLinkedList Users::searchByPhoneNumber(string pn) {
	return users.searchByPhoneNumber(pn);
}

//Accesses the searchByKeyword function in the userLinkedList class
UserLinkedList Users::searchByKeyword(string n) {
	return users.searchByKeyword(n);
}

//Get user at a specific position in a userLinkedList
User Users::getUserAt(int index) {
	return users.getNodeAt(index);
}

void Users::removeUser(User u) {
	users.removeNode(u);
}


//Accesses the printUserInfo function in the user class
void Users::printUserInfo(User u) {
	u.printUserInfo();
}

void Users::printAllUsers() {
	users.printAllUsers();
}

//Used to register new users in our library system
 void Users::registerUser(string fn, string ln, string a, string pn, string e, string p, int instID) {
	
	User u;
	u.setFirstName(fn);
	u.setLastName(ln);
	u.setAddress(a);
	u.setPhoneNumber(pn);
	u.setPassword(p);
	u.setInstructionID(instID);
	u.setIsGuest(false);

	//Ask teacher if we need to have a password

	//instID should have 8 numbers
	//having 5 in front means their id is a student id
	//having 6 in front means they are are an admin

	int val = instID / 60000000;

	if (val == 1) {
		u.setIsAdmin(true);
	}

	//Creates a library ID (which is 8 numbers long)
	
	//add something to check if a particular id was used before
	//u.setLibraryID(createLibraryID());

	//printing this out for testing purposes
	cout << u.getLibraryID() << endl;

	//check if donor by going through all of the books?
	//This function assumes you can't borrow books without having an account

	addUser(u);
}

 //ASK GROUP IF IT SHOULD BE RANDOM OR IF IT SHOULD COUNT BASED ON THE USERS
 //create global counter for new libraryID
 // NOT RANDOM
 /*
 int Users::createLibraryID() {
	 srand(time(0));
	 int upperBound = 50000000;
	 int lowerBound = 40000000;
	 int libraryID = ((rand() % (upperBound - lowerBound + 1)) + lowerBound);
	
	 


	 if (libraryID < upperBound && libraryID > lowerBound) {
		 return true; //Library ID is valid
	 }*/
 