#pragma once
#ifndef PublisherLinkedList_H
#define PublisherLinekdList_H
#include "PublisherNode.h"
#include "Publisher.h"
class PublisherLinkedList {
private:
	PublisherNode* head;
public:
	//Default Constructor
	PublisherLinkedList() { head = NULL; };

	//Copy Constructor
	//PublisherLinkedList(const PublisherLinkedList& publishers);

	//Destructor
	~PublisherLinkedList() {};

	//Add, Remove, and Get Functions
	void addPublisher(Publisher p);
	Publisher getPublisherByID(string id);
	bool find(Publisher p);
	//PeriodicalLinkedList searchByPrice(double p);
};

#endif