//Made by Alanna Siebers
#pragma once
#ifndef JournalLinkedList_H
#define JournalLinkedList_H
#include "JournalNode.h"
#include "Journals.h"

class JournalLinkedList {
private:
	JournalNode* head;
	string doubleToString(double num);
public:
	//Default Constructor
	JournalLinkedList();

	//Copy Constructor
	JournalLinkedList(const JournalLinkedList& journals);

	//Destructor
	~JournalLinkedList();

	//Add, Remove, and Get Functions
	void addJournal(Journals j);
	void removeJournal(string ISBN);
	Journals getJournal(string ISBN);
	Journals getJournalAt(int index);

	//Search Functions
	JournalLinkedList searchByAuthor(string a);
	JournalLinkedList searchByTitle(string t);
	JournalLinkedList searchByISBN(string isbn);
	JournalLinkedList searchByPrice(double p);

	//Other Functions
	void printAllJournals();
	JournalNode* getHead() { return head; }
};

#endif