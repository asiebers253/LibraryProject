#pragma once
#ifndef PeriodicalLinkedList_H
#define PeriodicalLinkedList_H
#include "PeriodicalNode.h"
#include "Periodicals.h"

class PeriodicalLinkedList
{
private:
	PeriodicalNode* head;
	string doubleToString(double d);
public:
	//Default Constructor
	PeriodicalLinkedList();

	//Copy Constructor
	PeriodicalLinkedList(const PeriodicalLinkedList& periodicals);

	//Destructor
	~PeriodicalLinkedList();

	//Add, Remove, and Get Funtions
	void addPeriodical(Periodicals p);
	void removePeriodical(string ISBN);
	Periodicals getPeriodical(string ISBN);
	Periodicals getPeriodicalAt(int index);

	//Search Functions
	PeriodicalLinkedList searchByTitle(string t);
	PeriodicalLinkedList searchByDate(string d);
	PeriodicalLinkedList searchByFrequency(string f);
	PeriodicalLinkedList searchByISBN(string ISBN);
	PeriodicalLinkedList searchByPrice(double p);

	//Other Functions
	void printAllPeriodicals();
	PeriodicalNode* getHead() { return head; }
};

#endif;