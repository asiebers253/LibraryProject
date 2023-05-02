//Made by Alanna Siebers
#include "JournalLinkedList.h"
#include "JournalNode.h"
#include "Journals.h"
#include <iostream>
#include <sstream>
using namespace std;

//Default Constructor
//JournalLinkedList::JournalLinkedList() { head = NULL; }

//Copy Constructor
JournalLinkedList::JournalLinkedList(const JournalLinkedList& journals) : head(journals.head) {};

//Deconstructor
JournalLinkedList::~JournalLinkedList() {}

//Adds a given journal to the JournalLinkedList
void JournalLinkedList::addJournal(Journals j) {
	JournalNode* newnode = new JournalNode();
	newnode->data = j;
	newnode->next = NULL;
	//once you created the first node
	if (head == NULL) {
		head = newnode;
	}
	else {
		JournalNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

//Removes a journal from the JournalLinkedList based on the given ISBN
void JournalLinkedList::removeJournal(string ISBN) {
	if (head == NULL) {
		cout << "Error - no journals to remove" << endl;
	}
	else {
		JournalNode* prevNode = head;
		JournalNode* currNode = head->next;
		while (currNode != NULL) {
			Journals currJournal = currNode->data;
			if (ISBN == currJournal.GetISBN()) {
				prevNode->next = currNode->next;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}
//Returns a journal from the JournalLinkedList based on the given ISBN
Journals JournalLinkedList::getJournal(string ISBN) {
	if (head != NULL) {
		JournalNode* temp = head;
		Journals tempJ;
		while (temp != NULL) {
			tempJ = temp->data;
			if (ISBN == tempJ.GetISBN()) {
				return tempJ;
			}
			temp = temp->next;
		}
	}
}

//Returns a journal from the JournalLinkedList based on the given index
Journals JournalLinkedList::getJournalAt(int index) {
	if (head == NULL) {
		cout << "Error - there are no journals to get";
	}
	else {
		JournalNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Journals tempJ = temp->data;
			if (counter == index) {
				return tempJ;
			}
			counter++;
			temp = temp->next;
		}
	}
}

//Prints all of the journals in the JournalLinkedList
void JournalLinkedList::printAllJournals() {
	if (head == NULL) {
		cout << "There are no users." << endl;
	}
	else {
		JournalNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Journals tempJ = temp->data;
			cout << " [" << counter << "] " << tempJ.GetTitle() << " by " << tempJ.GetAuthor() << endl;
			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}



//Returns a JournalLinkedList containing journals with any connection to the given author
JournalLinkedList JournalLinkedList::searchByAuthor(string a) {
	JournalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no journals to search";
	}
	else {
		JournalNode* temp = head;
		Journals tempJ;
		while (temp != NULL) {
			tempJ = temp->data;
			string author = tempJ.GetAuthor();
			if (author.find(a) != string::npos) {
				results.addJournal(tempJ);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns a JournalLinkedList containing journals with any connection to the given title
JournalLinkedList JournalLinkedList::searchByTitle(string t) {
	JournalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no journals to search";
	}
	else {
		JournalNode* temp = head;
		Journals tempJ;
		while (temp != NULL) {
			tempJ = temp->data;
			string title = tempJ.GetTitle();
			if (title.find(t) != string::npos) {
				results.addJournal(tempJ);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns a JournalLinkedList containing journals with any connection to the given ISBN
JournalLinkedList JournalLinkedList::searchByISBN(string isbn) {
	JournalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no journals to search";
	}
	else {
		JournalNode* temp = head;
		Journals tempJ;
		while (temp != NULL) {
			tempJ = temp->data;
			string ISBN = tempJ.GetISBN();
			if (ISBN.find(isbn) != string::npos) {
				results.addJournal(tempJ);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns a JournalLinkedList containing journals with any connection to the given price
JournalLinkedList JournalLinkedList::searchByPrice(double p) {
	JournalLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no journals to search";
	}
	else {
		JournalNode* temp = head;
		Journals tempJ;
		string givenPrice = doubleToString(p);
		while (temp != NULL) {
			tempJ = temp->data;
			double price = tempJ.GetPrice();
			string strPrice = doubleToString(price);
			if (strPrice.find(givenPrice) != string::npos) {
				results.addJournal(tempJ);
			}
			temp = temp->next;
		}
	}
	return results;
}



//Returns the string value of a given double
string JournalLinkedList::doubleToString(double num) {
	stringstream ss;
	string str;
	ss << num;
	ss >> str;
	return str;
}