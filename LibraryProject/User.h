#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Books.h"
using namespace std;
#ifndef USER_H
#define USER_H
#endif

class User
{
private:
	string firstName;
	string lastName;
	string address;
	string phoneNumber;
	string email;
	string password;
	int instructionID;
	int libraryID;
	bool isGuest;
	bool isAdmin;
	bool isDonor;
	vector<Books> borrowedBooks;
	

public:
	User();							//Default Constructor
	User(string fn, string ln, string a, string pN, string e, string p, int iID, int lID, bool donor);	//Parametric Constructor
	User(const User& u);			//Copy Constructor

	//Other Functions
	void printUserInfo();
	bool isEqual(User u);
	bool isValidLogin(string pwd); 
		bool isThereBorrowedBooks();
		void borrowBook(Books b);
		string test();

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
	int getInstructionID() const;
	void setInstructionID(int iID);
	int getLibraryID() const;
	void setLibraryID(int lID);
	bool getIsGuest() const;
	void setIsGuest(bool g);
	bool getIsAdmin() const;
	void setIsAdmin(bool admin);
	bool getIsDonor() const;
	void setIsDonor(bool d);
	vector<Books> getBorrowedBooks();
	void setBorrowedBooks(vector<Books> books);
	
};

