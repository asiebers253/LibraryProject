//Made by Alanna Siebers
#include "NewspaperLinkedList.h"
#include "NewspaperNode.h"
#include "Newspapers.h"
#include <iostream>
#include <sstream>
using namespace std;

//Default Constructor
NewspaperLinkedList::NewspaperLinkedList() { head = NULL; }

//Copy Constructor
NewspaperLinkedList::NewspaperLinkedList(const NewspaperLinkedList& newspapers) : head(newspapers.head) {}

//Deconstructor
NewspaperLinkedList::~NewspaperLinkedList() {}

//Adds a given newspaper to the NewspaperLinkedList
void NewspaperLinkedList::add(Newspapers n) {
	NewspaperNode* newnode = new NewspaperNode();
	newnode->data = n;
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode;
		size++;
	}
	else {
		NewspaperNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		size++;
	}
}

//Removes a newspaper from the NewspaperLinkedList based on the given ISBN
void NewspaperLinkedList::remove(string ISBN) {
	if (head == NULL) {
		cout << "Error - no newspapers to remove" << endl;
	}
	else {
		NewspaperNode* prevNode = head;
		NewspaperNode* currNode = head->next;
		while (currNode != NULL) {
			Newspapers currNewspaper = currNode->data;
			if (ISBN == currNewspaper.GetISBN()) {
				prevNode->next = currNode->next;
				size--;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}

//Returns a newspaper from the NewspaperLinkedList based on the given ISBN
Newspapers NewspaperLinkedList::get(string ISBN) {
	if (head != NULL) {
		NewspaperNode* temp = head;
		Newspapers tempN;
		while (temp != NULL) {
			tempN = temp->data;
			if (ISBN == tempN.GetISBN()) {
				return tempN;
			}
			temp = temp->next;
		}
	}
}

//Returns a newspaper from the NewspaperLinkedList based on the given index
Newspapers NewspaperLinkedList::getAt(int index) {
	if (head != NULL) {
		NewspaperNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			while (temp != NULL) {
				Newspapers tempN = temp->data;
				if (counter == index) {
					return tempN;
				}
				counter++;
				temp = temp->next;
			}
		}
	}
}

//Prints out all of the newspapers in the NewspaperLinkedList
void NewspaperLinkedList::printAll() {
	if (head == NULL) {
		cout << "There are no newspapers to print" << endl;
	}
	else {
		NewspaperNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			cout << " [" << counter << "] " << tempN.GetTitle() << endl;
			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}

//Searches the NewspaperLinkedList for newspapers with the given title
NewspaperLinkedList NewspaperLinkedList::searchByTitle(string t) {
	NewspaperLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no Newspapers to search";
	}
	else {
		NewspaperNode* temp = head;
		Newspapers tempJ;
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			string title = tempN.GetTitle();
			if (title.find(t) != string::npos) {
				results.add(tempN);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the NewspaperLinkedList for newspapers with the given date
NewspaperLinkedList NewspaperLinkedList::searchByDate(string d) {
	NewspaperLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no Newspapers to search";
	}
	else {
		NewspaperNode* temp = head;
		Newspapers tempJ;
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			string date = tempN.getDate();
			if (date.find(d) != string::npos) {
				results.add(tempN);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the NewspaperLinkedList for newspapers with the given frequency
NewspaperLinkedList NewspaperLinkedList::searchByFrequency(string f) {
	NewspaperLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no Newspapers to search";
	}
	else {
		NewspaperNode* temp = head;
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			string frequency = tempN.getFrequency();
			if (frequency.find(f) != string::npos) {
				results.add(tempN);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the NewspaperLinkedList for newspapers with the given ISBN
NewspaperLinkedList NewspaperLinkedList::searchByISBN(string isbn) {
	NewspaperLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no Newspapers to search";
	}
	else {
		NewspaperNode* temp = head;
		Newspapers tempJ;
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			string ISBN = tempN.GetISBN();
			if (ISBN.find(isbn) != string::npos) {
				results.add(tempN);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the NewspaperLinkedList for newspapers with the given price
NewspaperLinkedList NewspaperLinkedList::searchByPrice(double p) {
	NewspaperLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no Newspapers to search";
	}
	else {
		NewspaperNode* temp = head;
		Newspapers tempJ;
		string givenPrice = doubleToString(p);
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			double price = tempN.GetPrice();
			string strPrice = doubleToString(price);
			if (strPrice.find(givenPrice) != string::npos) {
				results.add(tempN);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns the string value of a given double
string NewspaperLinkedList::doubleToString(double num) {
	stringstream ss;
	string str;
	ss << num;
	ss >> str;
	return str;
}

//Returns the head of the linkedlist
NewspaperNode* NewspaperLinkedList::getHead() { return head; }

//Gets the size of the linkedlist
int NewspaperLinkedList::getSize() {
	if (head == NULL) {
		return 0;
	}
	else {
		NewspaperNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
}