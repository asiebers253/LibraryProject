//Made by Alanna Siebers
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
	PublisherLinkedList() {
		head = NULL;
	};

	//Copy Constructor
	PublisherLinkedList(const PublisherLinkedList& publishers);

	//Destructor
	~PublisherLinkedList();

	//Add and Get Functions
	void addPublisher(Publisher p);
	Publisher getPublisherByID(string id);
	bool find(Publisher p);
};

#endif