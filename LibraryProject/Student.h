#pragma once
#ifndef Student_H
#define Student_H

#include "User.h"
class Student : public User {
public:
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
	//Student() { studentID = 0; };
	~Student() {};
	//void print();
	bool isEqual(Student s);
};

#endif

