//Made by Alanna Siebers
#pragma once
#ifndef Student_H
#define Student_H

#include "User.h"
class Student : public User {
public:
	//Default Constructor
	Student() {};

	//Parametric Constructors
	Student(string fn, string ln, string a, string pN, string e, string p, string id, int lID, bool donor) {
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

	Student(string fn, string ln, string a, string pN, string e, string p, string id, int lID, bool donor, vector<BorrowedBook> books) {
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
	~Student() {};
};

#endif

