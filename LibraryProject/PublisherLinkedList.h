//Made by Alanna Siebers
#pragma once
#ifndef PublisherLinkedList_H
#define PublisherLinekdList_H
#include "PublisherNode.h"
#include "Publisher.h"
//This class was intended to be used to keep tract of all of the publishers
//This class is currently not being used

class PublisherLinkedList {
private:
	PublisherNode* head;
public:
	//Default Constructor
	PublisherLinkedList();

	//Copy Constructor
	PublisherLinkedList(const PublisherLinkedList& publishers);

	//Destructor
	~PublisherLinkedList();

	//Add and Find Functions
	void addPublisher(Publisher p);
	bool find(Publisher p);
};

#endif