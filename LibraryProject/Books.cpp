
#include "Books.h"
Books::Books() { "Rick Riordan"; "Percy Jackson"; "1"; "0000000001"; 10.0; }
Books::Books(string a, string t, int e, int i, double pr) : title(t), author(a), edition(e), ISBN(i), price(pr) {}
Books::~Books() {}

void Books::SetAuthor(string a) { author = a; }
string Books::GetAuthor() { return author; }

void Books::SetTitle(string t) { title = t; }
string Books::GetTitle() { return title; }

void Books::SetEdition(int e) { edition = e; }
int Books::GetEdition() { return edition; }

void Books::SetISBN(int i) { ISBN = i; }
int Books::GetISBN() { return ISBN; }

void Books::SetPrice(double pr) { price = pr; }
double Books::GetPrice() { return price; }