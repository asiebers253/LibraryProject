#include "User.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "Books.h"
using namespace std;

//Default Constructor (Creates an "blank" user);
User::User() {
	//shows all "empty" values for each variable
	firstName = "None";
	lastName = "None";
	address = "None";
	phoneNumber = "None";
	email = "None";
	password = "None";
	libraryID = 0;
	isDonor = false;
	vector<Books> empty;
	borrowedBooks = empty;
}

//Parametric Constructor (Used by Student and Employee classes)
User::User(string t, string fn, string ln, string a, string pN, string e, string p, int libID, bool donor) {
	type = t;
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	libraryID = libID;
	isDonor = donor;
	vector<Books> empty;
	borrowedBooks = empty;
}

//Copy Constructor
User::User(const User& u) : firstName(u.firstName), lastName(u.lastName), address(u.address), phoneNumber(u.phoneNumber), email(u.email), 
password(u.password), libraryID(u.libraryID), isDonor(u.isDonor), borrowedBooks(u.borrowedBooks) {}

//Getter Functions
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getAddress() const { return address; }
string User::getPhoneNumber() const { return phoneNumber; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
int User::getLibraryID() const { return libraryID; }
bool User::getIsDonor() const { return isDonor; }
vector<Books> User::getBorrowedBooks() const { return borrowedBooks; }

//Setter Functions
void User::setFirstName(string fn) { firstName = fn; }
void User::setLastName(string ln) { lastName = ln; }
void User::setAddress(string a) { address = a; }
void User::setPhoneNumber(string pN) { phoneNumber = pN; }
void User::setEmail(string e) { email = e; }
void User::setPassword(string p) { password = p; }
void User::setLibraryID(int lID) { libraryID = lID; }
void User::setIsDonor(bool d) { isDonor = d; }
void User::setBorrowedBooks(vector<Books> bks) { borrowedBooks = bks; }

//Checks if a login attempt was successful
bool User::isValidLogin(string pwd) {
	if (password == pwd) {
		return true;
	}
	return false;
}

//Add a book to the user's vector of borrowed books
void User::borrowBook(Books b) {
	borrowedBooks.push_back(b);
}
