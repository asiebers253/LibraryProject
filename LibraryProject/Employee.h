//Made by Alanna Siebers
#pragma once
#ifndef Employee_H
#define Employee_H

#include "User.h"
class Employee : public User {
public:
	Employee(string fn, string ln, string a, string pN, string e, string p, string id, int lID, bool donor);
	//Employee() {};
	~Employee() {};
	void print();
	bool isEqual(Employee e);
};

#endif

