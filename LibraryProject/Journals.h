//Made by Ryan Guay and Alanna Siebers
#pragma once
#ifndef JOURNALS_H
#define JOURNALS_H
#include "Inventory.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Journals : public Inventory {
private:
	string author = "";
	int edition = 0;

public:
	//Default Constructor
	Journals() {};

	//Parametric Constructor
	Journals(string author, string title, int edition, string ISBN, double price, Publisher p) 
		: author(author), edition(edition), Inventory(p, title, ISBN, price) {};
	
	//Deconstructor
	~Journals() {};

	//Getters and Setters
	string GetAuthor() { return author; }
	void SetAuthor(string a) { author = a; }
	int GetEdition() { return edition; }
	void SetEdition(int e) { edition = e; }

	//Prints out all of the relevant journal information
	void print() {
		cout << "Journal Information - " << title << endl;
		cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
		cout << "Author: " << author << endl;
		cout << "Edition: " << edition << endl;
		Inventory::print();
	}
};

#endif