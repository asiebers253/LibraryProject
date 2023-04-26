#pragma once
#ifndef Employee_H
#define Employee_H

#include "User.h"
class Employee : public User {
private:
	int employeeID;
public:
	Employee(string fn, string ln, string a, string pN, string e, string p, int id, int lID, bool donor);
	Employee() { employeeID = 0; };
	~Employee() {};
	void print();
	bool isEqual(Employee e);
	int getID() { return employeeID; }
	void setID(int id) { employeeID = id; }
};

#endif

