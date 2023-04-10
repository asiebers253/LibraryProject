#include "Users.h"
#include <iostream>
#include <cstring>
#include "UserLinkedList.h"
#include "User.h"
using namespace std;

//Default Constructor
Users::Users() {
	UserLinkedList users;
	this->users = users;
}

//Parametric Constructor
Users::Users(UserLinkedList users) {
	this->users = users;
}

//Copy Constructor
Users::Users(Users& u) {
	this->users = u.users;
}

//this will change when using linkedlists instead of vectors
void Users::addUser(User u) {
	users.addNode(u);
}

//search functions and printing search results will change after
//I have a better understanding of how linkedlist works in c++

UserLinkedList Users::searchByName(string n) {
	return users.searchByName(n);
}

UserLinkedList Users::searchByAddress(string a) {
	return users.searchByAddress(a);
}

UserLinkedList Users::searchByEmail(string e) {
	return users.searchByEmail(e);
}

UserLinkedList Users::searchByPhoneNumber(string pn) {
	return users.searchByPhoneNumber(pn);
}

UserLinkedList Users::searchByKeyword(string n) {
	return users.searchByKeyword(n);
}



//void Users::printSearchResults(/*linked list of results*/) {
	//for each value in the list, print the value
	//cout << "[" << i << "] " << (list.at(i)).getFirstName() << " " << (list.at(i)).getLastName();
//}

//this is just to make sure the code is working and will be replaced
//by search related functions later
/*void Users::printAllUsers() {
	cout << endl;
	for (int i = 0; i < users.size(); i++) {
		users.at(i).printUserInfo();
	}
}*/

void Users::printUserInfo(User u) {
	u.printUserInfo();
}

/*
void Users::registerUser() {
	User u;
	string str;
	int i;
	bool b;
	cout << endl;

	cout << "What is your first name? ";
	cin >> str;
	u.setFirstName(str);
	cout << endl;

	cout << "What is your last name? ";
	cin >> str;
	u.setLastName(str);
	cout << endl;

	cout << "What is your address? ";
	cin >> str;
	u.setAddress(str);
	cout << endl;

	cout << "What is your phone number? ";
	cin >> str;
	u.setPhoneNumber(str);
	cout << endl;

	cout << "What is your email? ";
	cin >> str;
	u.setEmail(str);
	cout << endl;

	cout << "What is your instruction ID?";
	cin >> i;
	//if valid, set instruction id
	//this also determines if the user is an admin

	//scan books to see if this user has donated to the library?


	//add something to create a password

	srand(time(0));
	int id = 843700000000;
	int idR = rand();
	idR = (idR % 100000) * 100;
	id += idR;
	u.setLibraryID(id);

	//randomness for the library id is currently not working

	cout << "Your registration is complete!" << endl;

	cout << "Your Library ID is " << u.getLibraryID() << endl;
	cout << "Use this along with your password to log onto the Cofrin Library system." << endl;

	//check in instruction id is admin to determine if user should be an admin
}
*/
