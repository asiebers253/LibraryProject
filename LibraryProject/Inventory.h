#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "Publisher.h"
#include <iostream>
using namespace std;

class Inventory {
public:
	Inventory(Publisher publisher, string title, string isbn, double pr) : publisher(publisher), title(title), ISBN(isbn), price(pr) {}
	Inventory() {};
	~Inventory() {};
	int getQuantity() {
		return quantity;
	}
	void subtractQuantity() {
		quantity--;
	}

	void addQuantity() {
		quantity++;
	}
	string GetTitle() { return title; }

	void SetTitle(string t) { title = t; }

	string GetISBN() { return ISBN; }

	void SetISBN(string i) { ISBN = i; }

	double GetPrice() { return price; }

	void SetPrice(double pr) { price = pr; }

	void print() {
		cout << " ISBN: " << ISBN << endl;
		cout << " Quantity: " << quantity << endl;
		cout << " Price: " << price << endl;
		cout << " Publisher: " << Inventory::publisher.getPublisherName() << endl;
		cout << endl;
	}

protected:
	Publisher publisher;
	int quantity = 3;
	string title = "";
	string ISBN;
	double price = 0.0;
};

#endif
