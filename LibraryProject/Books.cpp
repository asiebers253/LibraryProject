#include "Books.h"
Books::Books() { "Rick Riordan"; "Percy Jackson"; "New York Times"; "1"; "0000000001"; "NewYorkTimes@gmail.com"; "123 Main Street"; 10.0; }
Books::Books(string a, string t, string p, int e, int i, string pe, string pa, double pr) : title(t), author(a), publisher(p), edition(e), ISBN(i), publisherEmail(pe), publisherAddress(pa), price(pr) {}
Books::~Books() {}

void Books::SetAuthor(string a) { author = a; }
string Books::GetAuthor() { return author; }

void Books::SetTitle(string t) { title = t; }
string Books::GetTitle() { return title; }

void Books::SetPublisher(string p) { publisher = p; }
string Books::GetPublisher() { return publisher; }

void Books::SetEdition(int e) { edition = e; }
int Books::GetEdition() { return edition; }

void Books::SetISBN(int i) { ISBN = i; }
int Books::GetISBN() { return ISBN; }

void Books::SetPublisherEmail(string pe) { publisherEmail = pe; }
string Books::GetPublisherEmail() { return publisherEmail; }

void Books::SetPublisherAddress(string pa) { publisherAddress = pa; }
string Books::GetPublisherAddress() { return publisherAddress; }

void Books::SetPrice(double pr) { price = pr; }
double Books::GetPrice() { return price; }
