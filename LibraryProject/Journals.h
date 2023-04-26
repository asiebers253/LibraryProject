#ifndef JOURNALS_H
#define JOURNALS_H

#include "Inventory.h"
#include <string>
using namespace std;

class Journals : public Inventory {
private:
	string author;
	string title;
	int edition;
	int ISBN;
	double price;
public:
	Journals();
	Journals(string author, string title, int edition, int ISBN, double price);
	~Journals();

	string GetAuthor() {}

	void SetAuthor(string a) {}

	string GetTitle() {}

	void SetTitle(string t) {}

	int GetISBN() {}

	void SetISBN(int i) {}

	int GetEdition() {}

	void SetEdition(int e) {}

	double GetPrice() {}

	void SetPrice(double pr) {}
};

#endif
