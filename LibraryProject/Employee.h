//Made by Alanna Siebers
#pragma once
#ifndef Employee_H
#define Employee_H
#include "User.h"

class Employee : public User {
public:
	//Default Constructor
	Employee() {};

	//Parametric Constructors
	Employee(string fn, string ln, string a, string pN, string e, string p, string id, int lID, bool donor) {
		firstName = fn;
		lastName = ln;
		address = a;
		phoneNumber = pN;
		email = e;
		password = p;
		institutionalID = id;
		libraryID = lID;
		isDonor = donor;
	}

	Employee(string fn, string ln, string a, string pN, string e, string p, string id, int lID, bool donor, vector<BorrowedBook> books) {
		firstName = fn;
		lastName = ln;
		address = a;
		phoneNumber = pN;
		email = e;
		password = p;
		institutionalID = id;
		libraryID = lID;
		isDonor = donor;
		bb = books;
	}

	//Deconstructor
	~Employee() {};
};

#endif

