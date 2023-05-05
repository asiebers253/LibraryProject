//Made by Alanna Siebers
#include "PeriodicalLinkedList.h"
#include "PeriodicalNode.h"
#include "Periodicals.h"
#include <iostream>
#include <sstream>
using namespace std;

//Default Constructor
PeriodicalLinkedList::PeriodicalLinkedList() { head = NULL; }

//Copy Constructor
PeriodicalLinkedList::PeriodicalLinkedList(const PeriodicalLinkedList& periodicals) : head(periodicals.head) {};

//Deconstructor
PeriodicalLinkedList::~PeriodicalLinkedList() {};

//Adds a given periodical to the PeriodicalLinkedList
void PeriodicalLinkedList::addPeriodical(Periodicals p) {
	PeriodicalNode* newnode = new PeriodicalNode();
	newnode->data = p;
	newnode->next = NULL;
	//once you created the first node
	if (head == NULL) {
		head = newnode;
	}
	else {
		PeriodicalNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

//Removes a Periodical from the PeriodicalLinkedList based on the given ISBN
void PeriodicalLinkedList::removePeriodical(string ISBN) {
	if (head == NULL) {
		cout << "Error - no periodicals to remove" << endl;
	}
	else {
		PeriodicalNode* prevNode = head;
		PeriodicalNode* currNode = head->next;
		while (currNode != NULL) {
			Periodicals currPeriodical = currNode->data;
			if (ISBN == currPeriodical.GetISBN()) {
				prevNode->next = currNode->next;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}

//Returns a periodical from the PeriodicalLinkedList based on the given ISBN
Periodicals PeriodicalLinkedList::getPeriodical(string ISBN) {
	if (head != NULL) {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		while (temp != NULL) {
			tempP = temp->data;
			if (ISBN == tempP.GetISBN()) {
				return tempP;
			}
			temp = temp->next;
		}
	}
}

//Returns a periodical from the PeriodicalLinkedList based on the given index
Periodicals PeriodicalLinkedList::getPeriodicalAt(int index) {
	if (head == NULL) {
		cout << "Error - there are no journals to get";
	}
	else {
		PeriodicalNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Periodicals tempJ = temp->data;
			if (counter == index) {
				return tempJ;
			}
			counter++;
			temp = temp->next;
		}
	}
}

//Prints all of the periodicals in the PeriodicalLinkedList
void PeriodicalLinkedList::printAllPeriodicals() {
	if (head == NULL) {
		cout << "Error - there are no periodicals to print." << endl;
	}
	else {
		PeriodicalNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Periodicals tempP = temp->data;
			cout << " [" << counter << "] " << tempP.GetTitle() << endl;
			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}

//Searches the PeriodicalLinekdList for periodicals with the given price
PeriodicalLinkedList PeriodicalLinkedList::searchByPrice(double p) {
	PeriodicalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no periodicals to search";
	}
	else {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		string givenPrice = doubleToString(p);
		while (temp != NULL) {
			tempP = temp->data;
			double price = tempP.GetPrice();
			string strPrice = doubleToString(price);
			if (strPrice.find(givenPrice) != string::npos) {
				results.addPeriodical(tempP);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the PeriodicalinkedList for periodicals with the given title
PeriodicalLinkedList PeriodicalLinkedList::searchByTitle(string t) {
	PeriodicalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no periodicals to search";
	}
	else {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		while (temp != NULL) {
			tempP = temp->data;
			string title = tempP.GetTitle();
			if (title.find(t) != string::npos) {
				results.addPeriodical(tempP);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the PeriodicalinkedList for periodicals with the given date
PeriodicalLinkedList PeriodicalLinkedList::searchByDate(string d) {
	PeriodicalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no periodicals to search";
	}
	else {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		while (temp != NULL) {
			tempP = temp->data;
			string date = tempP.getDate();
			if (date.find(d) != string::npos) {
				results.addPeriodical(tempP);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the PeriodicalinkedList for periodicals with the given ISBN
PeriodicalLinkedList PeriodicalLinkedList::searchByISBN(string isbn) {
	PeriodicalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no periodicals to search";
	}
	else {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		while (temp != NULL) {
			tempP = temp->data;
			string ISBN = tempP.GetISBN();
			if (ISBN.find(isbn) != string::npos) {
				results.addPeriodical(tempP);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Searches the PeriodicalinkedList for periodicals with the given frequency
PeriodicalLinkedList PeriodicalLinkedList::searchByFrequency(string f) {
	PeriodicalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no periodicals to search";
	}
	else {
		PeriodicalNode* temp = head;
		Periodicals tempP;
		while (temp != NULL) {
			tempP = temp->data;
			string frequency = tempP.getFrequency();
			if (frequency.find(f) != string::npos) {
				results.addPeriodical(tempP);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns the string value of a given double
string PeriodicalLinkedList::doubleToString(double num) {
	stringstream ss;
	string str;
	ss << num;
	ss >> str;
	return str;
}