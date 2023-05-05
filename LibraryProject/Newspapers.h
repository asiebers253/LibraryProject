//Made by Ryan Guay and Alanna Siebers
#pragma once
#ifndef NEWSPAPERS_H
#define NEWSPAPERS_H
#include "Inventory.h"
#include <string>
#include <iomanip>
using namespace std;

class Newspapers : public Inventory {
private:
	string date;
	string frequency;
public:
	//Default Constructor
	Newspapers() {};
	//Parametric Constructor
	Newspapers(string t, string d, string f, string isbn, double price, Publisher p) 
		: date(d), frequency(f), Inventory(p, t, isbn, price) {};

	//Deconstructor
	~Newspapers() {};

	//Getters and Setters
	void setDate(string d) { date = d; }
	void setFrequency(string f) { frequency = f; }
	string getDate() { return date; }
	string getFrequency() { return frequency; }

	//Prints out all of the relevent newspaper information
	void print() {
		cout << "Newspaper Information - " << title << endl;
		cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
		cout << "Date: " << date << endl;
		cout << "Frequency: " << frequency << endl;
		Inventory::print();
	}
};

#endif