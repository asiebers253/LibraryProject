
#include "Books.h"
#include <iostream>
#include <iomanip>
using namespace std;

Books::Books() {}
Books::Books(string a, string t, int e, string g, string i, double pr, Publisher p) : author(a), edition(e), genre(g), Inventory(p, t, i, pr) {}
Books::~Books() {}

void Books::SetAuthor(string a) { author = a; }
string Books::GetAuthor() { return author; }

void Books::SetTitle(string t) { title = t; }
string Books::GetTitle() { return title; }

void Books::SetEdition(int e) { edition = e; }
int Books::GetEdition() { return edition; }

void Books::SetISBN(string i) { ISBN = i; }
string Books::GetISBN() { return ISBN; }

void Books::SetPrice(double pr) { price = pr; }
double Books::GetPrice() { return price; }

void Books::print() {
	cout << " Book Information - " << title << endl;
	cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
	cout << " Author: " << author << endl;
	cout << " Edition: " << edition << endl;
	cout << " Genre: " << genre << endl;
	Inventory::print();
}