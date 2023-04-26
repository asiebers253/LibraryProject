#include "User.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "Books.h"
using namespace std;

//Default Constructor
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
	vector<Books> empty;
	borrowedBooks = empty;
}

//Parametric Constructor (No Borrowed Books)
User::User(string fn, string ln, string a, string pN, string e, string p, int iID, int lID, bool donor) {
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	instructionID = iID;
	libraryID = lID;
	isGuest = false;
	if (iID / 60000000 == 1) {
		isAdmin = true;
	}
	else {
		isAdmin = false;
	}
	isDonor = donor;
	vector<Books> empty;
	borrowedBooks = empty;
}

//Parametric Constructor (For RegisterUser function in UserLinkedList)
User::User(string fn, string ln, string a, string pN, string e, string p, int iID, bool donor) {
	firstName = fn;
	lastName = ln;
	address = a;
	phoneNumber = pN;
	email = e;
	password = p;
	instructionID = iID;
	libraryID = 0;
	isGuest = false;
	if (iID / 60000000 == 1) {
		isAdmin = true;
	}
	else {
		isAdmin = false;
	}
	isDonor = donor;
	vector<Books> empty;
	borrowedBooks = empty;
}

//Copy Constructor
User::User(const User& u) : firstName(u.firstName), lastName(u.lastName), address(u.address), phoneNumber(u.phoneNumber), email(u.email), 
password(u.password), instructionID(u.instructionID), libraryID(u.libraryID), isGuest(u.isGuest), isAdmin(u.isAdmin), isDonor(u.isDonor), borrowedBooks(u.borrowedBooks) {}

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
vector<Books> User::getBorrowedBooks() const { return borrowedBooks; }

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
void User::setBorrowedBooks(vector<Books> bks) { borrowedBooks = bks; }

//Prints all of the relevant information about the user
void User::print() {
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
	if (borrowedBooks.empty()) {
		cout << " This user is not currently borrowing any books." << endl;
	}
	else {
		cout << " Currently borrowed books: " << endl;
		string books = " ";
		for (Books b : borrowedBooks) {
			books += b.GetTitle() + ", ";
		}
		books = books.substr(0, books.length() - 2);
		cout << books << endl;
	}
	cout << endl;
}

//Not Finished!
//Checks if the user is equal to a given user
bool User::isEqual(User u) {
	bool sN = false, sA = false, sPN = false, sE = false, sP = false, sIID = false, sLID = false, sPER = false, sD = false, sBB = false;

	if (firstName == u.getFirstName() && lastName == u.getLastName()) { sN = true; }
	if (address == u.getAddress()) { sA = true; }
	if (email == u.getEmail()) { sE = true; }
	if (phoneNumber == u.getPhoneNumber()) { sPN = true; }
	if (password == u.getPassword()) { sP = true; }
	if (instructionID == u.getInstructionID()) { sIID = true; }
	if (libraryID == u.getLibraryID()) { sLID = true; }
	if (u.getIsGuest() == false && isAdmin == u.getIsAdmin()) { sPER = true; }
	if (isDonor == u.getIsDonor()) { sD = true; }
	//something to check if books are equal to each other should be added to the book class

	if (sN && sA && sPN && sE && sP && sIID && sLID && sPER && sD) { return true; } else { return false; }
}

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
