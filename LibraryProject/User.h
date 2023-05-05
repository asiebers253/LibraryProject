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

class User {
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
	vector<BorrowedBook> bb;
public:
	//Default Constructor
	User();

	//Parametric Constructor
	User(string fn, string ln, string a, string pN, string e, string p, string instID, int libID, bool donor);
	User(string fn, string ln, string a, string pN, string e, string p, string instID, int libID, bool donor, vector<BorrowedBook> BB);
	
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
	vector<BorrowedBook> getBorrowedBooks();
	void setBorrowedBooks(vector<BorrowedBook> books);
	
	//Other Functions
	bool isValidLogin(string pwd);
	void borrowBook(Books b);
	void returnBook(Inventory i);
	bool hasBorrowedBook(Inventory i);
	void print();
};

#endif