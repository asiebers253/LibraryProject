//Made by Ryan Guay and Alanna Siebers
#pragma once
#ifndef books_h
#define books_h
#include "Inventory.h"
#include <string>
#include <iomanip>
using namespace std;

class Books : public Inventory {
private:
	string author;
	int edition;
	string genre;
public:
	//Default Constructor
	Books() {};

	//Parametric Constructor
	Books(string author, string title, int edition, string genre, string ISBN, double price, Publisher p)
		: author(author), edition(edition), genre(genre), Inventory(p, title, ISBN, price) {};

	//Deconstructor
	~Books() {};

	//Getters and Setters
	void SetAuthor(string a) { author = a; };
	string GetAuthor() { return author; };
	void SetEdition(int e) { edition = e; };
	int GetEdition() { return edition; };
	string GetGenre() { return genre; };
	void SetGenre(string g) { genre = g; };

	//Prints out all of the relevant book information
	void print() {
		cout << " Book Information - " << title << endl;
		cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
		cout << " Author: " << author << endl;
		cout << " Edition: " << edition << endl;
		cout << " Genre: " << genre << endl;
		Inventory::print();
	}
};

#endif