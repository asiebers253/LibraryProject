#include "User.h"
#include <iostream>
#include <cstring>
using namespace std;

//add something to create users with randomly generated ids for library id?

//Default Constructor (Guest User Constructor)
User::User() {
	//shows all "empty" values for each variable
	firstName = "None";
	lastName = "None";
	address = "None";
	phoneNumber = "None";
	email = "None";
	password = "None";
	instructionID = 0;
	libraryID = 0;
	isGuest = true;
	isAdmin = false;
	isDonor = false;
	//borrowedBooks = null;
}

//Parametric Constructors (Standard User and Admin User Constructor)

//
User::User(string fn, string ln, string a, string pN, string e, string p, int iID, int lID, bool authorized, bool donor/*, vector<Book> books = */) {
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	instructionID = iID;
	libraryID = lID;
	isGuest = false;
	if (authorized) {
		isAdmin = true;
	} else {
		isAdmin = false;
	}
	isDonor = donor;
	//borrowedBooks = books;
}

//Copy Constructor
User::User(const User& u) : firstName(u.firstName), lastName(u.lastName), address(u.address), phoneNumber(u.phoneNumber), email(u.email), 
password(u.password), instructionID(u.instructionID), libraryID(u.libraryID), isGuest(u.isGuest), isAdmin(u.isAdmin), isDonor(u.isDonor) {}

//Getter Functions
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getAddress() const { return address; }
string User::getPhoneNumber() const { return phoneNumber; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
int User::getInstructionID() const { return instructionID; }
int User::getLibraryID() const { return libraryID; }
bool User::getIsGuest() const { return isGuest; }
bool User::getIsAdmin() const { return isAdmin; }
bool User::getIsDonor() const { return isDonor; }
//vector<Book> User::getBorrowedBooks() const { return borrowedBooks; }

//Setter Functions
void User::setFirstName(string fn) { firstName = fn; }
void User::setLastName(string ln) { lastName = ln; }
void User::setAddress(string a) { address = a; }
void User::setPhoneNumber(string pN) { phoneNumber = pN; }
void User::setEmail(string e) { email = e; }
void User::setPassword(string p) { password = p; }
void User::setInstructionID(int iID) { instructionID = iID; }
void User::setLibraryID(int lID) { libraryID = lID; }
void User::setIsGuest(bool g) { isGuest = g; }
void User::setIsAdmin(bool admin) { isAdmin = admin; }
void User::setIsDonor(bool d) { isDonor = d; }
//void User::setBorrowedBooks(vector<book> books) { borrowedBooks = books; }

void User::printUserInfo() {
	cout << " User Information - " << firstName << " " << lastName << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Address: " << address << endl;
	cout << " Phone Number: " << phoneNumber << endl;
	cout << " Email: " << email << endl;
	cout << " Instruction ID: " << instructionID << endl;
	cout << " Library ID: " << libraryID << endl;
	cout << " Are they a donator to the library? ";
	if (isDonor) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	/*if (the user has borrowed books) {
		for (the size of the vector or linkedlist) {
			print out every book title in the list
		}
	}*/
	cout << endl;
}


