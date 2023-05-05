//Made by Ryan Guay and Alanna Siebers
#pragma once
#ifndef PERIODICALS_H
#define PERIODICALS_H
#include "Inventory.h"
#include <string>
#include <iomanip>
using namespace std;

class Periodicals : public Inventory {
private:
	string date;
	string frequency;
public:
	//Default Constructor
	Periodicals() {};

	//Parametric Constructor
	Periodicals(string title, string date, string frequency, string ISBN, double price, Publisher p) 
		: date(date), frequency(frequency), Inventory(p, title, ISBN, price) {}

	//Deconstructor
	~Periodicals() {};

	//Getters and Setters
	void setDate(string d) { date = d; }
	void setFrequency(string f) { frequency = f; }
	string getDate() { return date; }
	string getFrequency() { return frequency; }
	
	//Prints out all of the relevent periodical information
	void print() {
		cout << "Periodical Information - " << title << endl;
		cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
		cout << "Date: " << date << endl;
		cout << "Frequency: " << frequency << endl;
		Inventory::print();
	}
};

#endif