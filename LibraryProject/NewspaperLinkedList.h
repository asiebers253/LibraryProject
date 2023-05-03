//Made by Alanna Siebers
#pragma once
#ifndef NewspaperLinkedList_H
#define NewspaperLinkedList_H
#include "NewspaperNode.h"
#include "Newspapers.h"

class NewspaperLinkedList {
private:
	NewspaperNode* head;
	string doubleToString(double d);
public:
	//Default Constructor
	NewspaperLinkedList();

	//Copy Constructor
	NewspaperLinkedList(const NewspaperLinkedList& newspapers);

	//Destructor
	~NewspaperLinkedList();

	//Add, Remove, and Get Funtions
	void add(Newspapers n);
	void remove(string ISBN);
	Newspapers get(string ISBN);
	Newspapers getAt(int index);

	//Search Functions
	NewspaperLinkedList searchByTitle(string t);
	NewspaperLinkedList searchByDate(string d);
	NewspaperLinkedList serchByFrequency(string f);
	NewspaperLinkedList searchByISBN(string ISBN);
	NewspaperLinkedList searchByPrice(double p);

	//Other Functions
	void printAll();
	NewspaperNode* getHead();

};

#endif;