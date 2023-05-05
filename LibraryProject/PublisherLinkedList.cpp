//Made by Alanna Siebers
#include "PublisherLinkedList.h"
#include "PublisherNode.h"
#include "Publisher.h"

//Default Constructor
PublisherLinkedList::PublisherLinkedList() { head == NULL; };

//Copy Constructor
PublisherLinkedList::PublisherLinkedList(const PublisherLinkedList& publishers) : head(publishers.head) {}

//Deconstructor
PublisherLinkedList::~PublisherLinkedList() {}

void PublisherLinkedList::addPublisher(Publisher p) {
	PublisherNode* newnode = new PublisherNode();
	newnode->data = p;
	newnode->next = NULL;
	//once you created the first node
	if (head == NULL) {
		head = newnode;
	}
	else {
		PublisherNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

/*
Publisher PublisherLinkedList::getPublisherByID(string id) {
	Publisher p;
	if (head != NULL) {
		PublisherNode* temp = head;
		Publisher tempU;
		while (temp != NULL) {
			tempU = temp->data;

			if (id == tempU.getID()) {
				return tempU;
			}
			temp = temp->next;
		}
	}
	return p;
}*/

bool PublisherLinkedList::find(Publisher p) {
	bool result = false;
	if (head != NULL) {
		PublisherNode* temp = head;
		Publisher tempP;
		while (temp != NULL) {
			tempP = temp->data;
			string name = tempP.getPublisherName();
			string email = tempP.getPublisherEmail();
			string address = tempP.getPublisherAddress();

			if (name == p.getPublisherName()) {
				if (email == p.getPublisherEmail()) {
					if (address == p.getPublisherAddress()) {
						result = true;
					}
				}
			}
		}
	}
	return result;
}
