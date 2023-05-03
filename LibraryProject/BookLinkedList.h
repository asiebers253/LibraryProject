//Made by Alanna Siebers
#pragma once
#ifndef BookLinkedList_H
#define BookLinkedList_H
#include "BookNode.h"
#include "Books.h"
class BookLinkedList {
private:
	BookNode* head;
	int size = 0;
	string doubleToString(double d);
public:
	//Default Constructor
	BookLinkedList();

	//Copy Constructor
	BookLinkedList(const BookLinkedList& books);

	//Destructor
	~BookLinkedList();

	//Add, Remove, and Get Functions
	void addBook(Books b);
	void remove(string ISBN);
	Books get(string ISBN);
	Books getAt(int index);
	int getSize() { return size; };

	//Search Functions
	BookLinkedList searchByAuthor(string a);
	BookLinkedList searchByTitle(string title);
	BookLinkedList searchByPublisherName(string n);
	BookLinkedList searchByISBN(string ISBN);
	BookLinkedList searchByPrice(double price);
	BookLinkedList searchByGenre(string g);

	//Other Functions
	void printAllBooks();
	BookNode* getHead() { return head; }
};

#endif