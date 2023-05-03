//Made by Alanna Siebers
#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <cstring>
#include <vector>
#include "Books.h"
#include "BorrowedBook.h"
using namespace std;

//add a fee variable? and also a fee class?

class User
{
protected:
	string firstName;
	string lastName;
	string address;
	string phoneNumber;
	string email;
	string password;
	string institutionalID;
	double fines = 0;
	int libraryID;
	bool isDonor;
	//vector<Books> books;
	vector<BorrowedBook> bb;

public:
	//Default Constructor
	User();
	//Parametric Constructors
	User(string fn, string ln, string a, string pN, string e, string p, string instID, int libID, bool donor);
	//Copy Constructor
	User(const User& u);

	//Getters and Setters
	string getFirstName() const;
	void setFirstName(string fn);
	string getLastName() const;
	void setLastName(string ln);
	string getAddress() const;
	void setAddress(string a);
	string getPhoneNumber() const;
	void setPhoneNumber(string pN);
	string getEmail() const;
	void setEmail(string e);
	string getPassword() const;
	void setPassword(string p);
	string getInstitutionalID() const;
	void setInstitutionalID(string instID);
	int getLibraryID() const;
	void setLibraryID(int lID);
	bool getIsDonor() const;
	void setIsDonor(bool d);
	vector<BorrowedBook> getBorrowedBooks() const;
	void setBorrowedBooks(vector<BorrowedBook> books);
	

	//Other Functions
	bool isValidLogin(string pwd);
	void borrowBook(Books b);

	//functions needed in the Student and Employee classes
	int getID() { return 0; };
	void setID(int id) {};
	bool isEqual(User u) {};
	void print() {
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


	void returnBook(Inventory i);
};

#endif