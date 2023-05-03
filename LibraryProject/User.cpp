//Made by Alanna Siebers
#include "User.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "Books.h"
#include "BorrowedBook.h"
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
	vector<BorrowedBook> empty;
	bb = empty;
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
	vector<BorrowedBook> empty;
	bb = empty;
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
vector<BorrowedBook> User::getBorrowedBooks() const { return bb; }

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

//Add a book to the user's vector of borrowed books
void User::borrowBook(Books b) {
	BorrowedBook B(b);
	bb.push_back(B);
	b.subtractQuantity();
}

void User::returnBook(Inventory i) {
	int count = 0;
	for (int j = 0; j < bb.size(); j++) {
		if (i.GetISBN() == bb.at(j).getBook().GetISBN()) {
			break;
		}
		count++;
	}
	BorrowedBook b = bb.at(count);
	b.getBook().addQuantity();
	fines = b.calculateFines();

	bb.erase(bb.begin() + count);
}