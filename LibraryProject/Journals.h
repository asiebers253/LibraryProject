//Made by Ryan Guay and Alanna Siebers
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
	Journals() {};
	Journals(string author, string title, int edition, string ISBN, double price) {};
	Journals(string author, string title, int edition, string ISBN, double price, Publisher p) : author(author), edition(edition), Inventory(p, title, ISBN, price) {};
	//~Journals();

	string GetAuthor() { return author; }

	void SetAuthor(string a) { author = a; }

	int GetEdition() { return edition; }

	void SetEdition(int e) { edition = e; }

	void print() {
		cout << "Journal Information - " << title << endl;
		cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
		cout << "Author: " << author << endl;
		cout << "Edition: " << edition << endl;
		Inventory::print();
	}
};

#endif
