//Made by Alanna Siebers
#include "User.h"
#include "Books.h"
#include "BorrowedBook.h"
#include <iostream>
#include <cstring>
#include <vector>
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
	institutionalID = "None";
	libraryID = 0;
	isDonor = false;
}

//Parametric Constructors
User::User(string fn, string ln, string a, string pN, string e, string p, string instID, int libID, bool donor) {
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	institutionalID = instID;
	libraryID = libID;
	isDonor = donor;
}

User::User(string fn, string ln, string a, string pN, string e, string p, string instID, int libID, bool donor, vector<BorrowedBook> BB) {
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	institutionalID = instID;
	libraryID = libID;
	isDonor = donor;
	bb = BB;
}

//Copy Constructor
User::User(const User& u) : firstName(u.firstName), lastName(u.lastName), address(u.address), phoneNumber(u.phoneNumber), email(u.email), 
password(u.password), institutionalID(u.institutionalID), libraryID(u.libraryID), isDonor(u.isDonor), bb(u.bb) {}

//Getter Functions
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getAddress() const { return address; }
string User::getPhoneNumber() const { return phoneNumber; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
string User::getInstitutionalID() const { return institutionalID; }
int User::getLibraryID() const { return libraryID; }
bool User::getIsDonor() const { return isDonor; }
vector<BorrowedBook> User::getBorrowedBooks() { return bb; }

//Setter Functions
void User::setFirstName(string fn) { firstName = fn; }
void User::setLastName(string ln) { lastName = ln; }
void User::setAddress(string a) { address = a; }
void User::setPhoneNumber(string pN) { phoneNumber = pN; }
void User::setEmail(string e) { email = e; }
void User::setPassword(string p) { password = p; }
void User::setInstitutionalID(string instID) { institutionalID = instID; }
void User::setLibraryID(int lID) { libraryID = lID; }
void User::setIsDonor(bool d) { isDonor = d; }
void User::setBorrowedBooks(vector<BorrowedBook> bks) { bb = bks; }

//Checks if a login attempt was successful
bool User::isValidLogin(string pwd) {
	if (password == pwd) {
		return true;
	}
	return false;
}

//Adds a book to the user's vector of borrowed books
void User::borrowBook(Books b) {
	BorrowedBook B(b);
	char c = institutionalID.at(0);
	if (c == 'S' && bb.size() >= 4) {
		cout << "You currently have the max amount of borrowed books!" << endl;
		cout << "Sorry, you can't borrow this book." << endl;
		return;
	}
	else if (hasBorrowedBook(b)) {
		cout << "You have aleady borrowed this book!" << endl;
		return;
	}
	bb.push_back(B);
}

//Returns a BorrowedBook by removing it from the BorrowedBook vector 
//and also adds any fines to the user's account
void User::returnBook(Inventory i) {
	int count = 0;
	BorrowedBook b;
	for (int j = 0; j < bb.size(); j++) {
		if (i.GetISBN() == bb.at(j).getBook().GetISBN()) {
			BorrowedBook b = bb.at(count);
			fines = b.calculateFines();
			bb.erase(bb.begin() + count);
		}
		count++;
	}
}

//Returns a bool based on if the user has borrowed a given inventory object
bool User::hasBorrowedBook(Inventory i) {
	for (int j = 0; j < bb.size(); j++) {
		if (i.GetISBN() == bb.at(j).getBook().GetISBN()) {
			return true;
		}
	}
	return false;
}

//Prints the relevant information for a user
void User::print() {
	cout << " User Information - " << firstName << " " << lastName << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Address: " << address << endl;
	cout << " Phone Number: " << phoneNumber << endl;
	cout << " Email: " << email << endl;
	cout << " Institution ID: " << institutionalID << endl;
	cout << " Library ID: " << libraryID << endl;
	cout << " Current Fines: " << fines << endl;
	cout << " Are they a donator to the library? ";
	if (isDonor) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	if (bb.empty()) {
		cout << " This user is not currently borrowing any books." << endl;
	}
	else {
		cout << " Currently borrowed books: " << endl;
		string books = " ";
		for (BorrowedBook b : bb) {
			books += b.getBook().GetTitle() + ", ";
		}
		books = books.substr(0, books.length() - 2);
		cout << books << endl;
	}
	cout << endl;
}