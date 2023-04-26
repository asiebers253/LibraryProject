#pragma once
#ifndef Student_H
#define Student_H

#include "User.h"
class Student : public User {
private:
	int studentID;
public:
	Student(string fn, string ln, string a, string pN, string e, string p, int stuID, int lID, bool donor)
		: User("Student", fn, ln, a, pN, e, p, lID, donor), studentID(stuID) {};
	Student() { studentID = 0; };
	~Student() {};
	//void print();
	bool isEqual(Student s);
	int getID() { return studentID; }
	void setID(int id) { studentID = id; }
};

#endif