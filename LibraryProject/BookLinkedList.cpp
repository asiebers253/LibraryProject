//Made by Alanna Siebers
#include "BookLinkedList.h"
#include "BookNode.h"
#include "Books.h"
#include <iostream>
#include <sstream>
using namespace std;

//Default Constructor
BookLinkedList::BookLinkedList() { head = NULL; size = 0;}

//Copy Constructor
BookLinkedList::BookLinkedList(const BookLinkedList& books) {
	head = books.head;
	size = books.size;
}

//Deconstructor
BookLinkedList::~BookLinkedList() {}

void BookLinkedList::addBook(Books b) {
	size++;
	BookNode* newnode = new BookNode();
	newnode->data = b;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
	}
	else {
		BookNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		
	}
}

void BookLinkedList::remove(string ISBN) {
	
	if (head == NULL) {
		cout << "Error - no books to remove" << endl;
	}
	else {
		BookNode* prevNode = head;
		BookNode* currNode = head->next;
		while (currNode != NULL) {
			Books currBook = currNode->data;
			if (ISBN == currBook.GetISBN()) {
				prevNode->next = currNode->next;
				size--;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}

Books BookLinkedList::get(string ISBN) {
	if (head != NULL) {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			if (ISBN == tempB.GetISBN()) {
				return tempB;
			}
			temp = temp->next;
		}
	}
}

Books BookLinkedList::getAt(int index) {
	if (head != NULL) {
		BookNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Books tempB = temp->data;
			if (counter == index) {
				return tempB;
			}
			counter++;
			temp = temp->next;
		}
	}
}

void BookLinkedList::printAllBooks() {
	if (head == NULL) {
		cout << "Error - there are no books to print." << endl;
	}
	else {
		BookNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			Books tempB = temp->data;
			cout << " [" << counter << "] " << tempB.GetTitle() << endl;
			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}

BookLinkedList BookLinkedList::searchByPrice(double p) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		string givenPrice = doubleToString(p);
		while (temp != NULL) {
			tempB = temp->data;
			double price = tempB.GetPrice();
			string strPrice = doubleToString(price);
			if (strPrice.find(givenPrice) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
	return results;
}

BookLinkedList BookLinkedList::searchByTitle(string t) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			string title = tempB.GetTitle();
			if (title.find(t) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
	return results;
}

BookLinkedList BookLinkedList::searchByISBN(string isbn) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			string ISBN = tempB.GetISBN();
			if (ISBN.find(isbn) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
	return results;
}

BookLinkedList BookLinkedList::searchByAuthor(string a) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			string author = tempB.GetAuthor();
			if (author.find(a) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
	return results;
}

BookLinkedList BookLinkedList::searchByPublisherName(string pName) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			string publisherName = (tempB.GetPublisher().getPublisherName());
			if (publisherName.find(pName) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
}

BookLinkedList BookLinkedList::searchByGenre(string g) {
	BookLinkedList results;
	if (head == NULL) {
		cout << "Error - there are no books to search";
	}
	else {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			tempB = temp->data;
			string genre = tempB.GetGenre();
			if (genre.find(g) != string::npos) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
	return results;
}

//Returns the string value of a given double
string BookLinkedList::doubleToString(double num) {
	stringstream ss;
	string str;
	ss << num;
	ss >> str;
	return str;
}