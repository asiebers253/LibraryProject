
#include "Books.h"
Books::Books() {}
Books::Books(string a, string t, int e, string i, string g, double pr, Publisher p) : title(t), author(a), edition(e), genre(g), ISBN(i), price(pr), Inventory(p) {}
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