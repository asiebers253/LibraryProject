//Made by Ryan Guay and Alanna Siebers
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Publisher.h"
#include <string>
#include <iostream>
using namespace std;

class Inventory {
protected:
	Publisher publisher;
	string title = "";
	string ISBN;
	double price = 0.0;
public:
	//Default Constructor
	Inventory() {};

	//Parametric Constructor
	Inventory(Publisher publisher, string title, string isbn, double pr) : publisher(publisher), title(title), ISBN(isbn), price(pr) {}

	//Deconstructor
	~Inventory() {};

	//Getters and Setters
	string GetTitle() { return title; }
	void SetTitle(string t) { title = t; }
	string GetISBN() { return ISBN; }
	void SetISBN(string i) { ISBN = i; }
	double GetPrice() { return price; }
	void SetPrice(double pr) { price = pr; }
	Publisher GetPublisher() { return publisher; };
	void SetPublisher(Publisher p) { publisher = p; }

	//Print the relevent information for an inventory object
	void print() {
		cout << " ISBN: " << ISBN << endl;
		cout << " Price: " << price << endl;
		cout << " Publisher: " << Inventory::publisher.getPublisherName() << endl;
		cout << endl;
	}
};

#endif
