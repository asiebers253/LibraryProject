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

//Adds a given book to the linked list
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

//Remove a book from the linked list based on the given ISBN
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

//Get the book in the linked list which has the same ISBN as the given ISBN
Books BookLinkedList::get(string ISBN) {
	Books b;
	b.SetTitle("no match");
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
		return b;
	}
	return b;
}

//Get the book in the linked list at the given index
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

//Print all of the books in the linked list
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

//Searches the linked list for books with the given price
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

//Searches the linked list for books with the given title
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

//Searches the linked list for books with the given ISBN
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

//Searches the linked list for books with the given Author
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

//Searches the linked list for books with the given publisher name
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

//Searches the linked list for books with the given genre
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

//Searches the linked list for books with the given keyword
BookLinkedList BookLinkedList::searchByKeyword(string key) {
	BookLinkedList results;
	if (head != NULL) {
		BookNode* temp = head;
		Books tempB;
		while (temp != NULL) {
			
			//Getting all of the relevant data values from the current node
			string title = tempB.GetTitle();
			string ISBN = tempB.GetISBN();
			string pubName = tempB.GetPublisher().getPublisherName();
			string author = tempB.GetAuthor();
			string genre = tempB.GetGenre();

			//Check if any of the data values have the key
			bool keyInTitle = (title.find(key) != string::npos);
			bool keyInISBN = (ISBN.find(key) != string::npos);
			bool keyInPubName = (pubName.find(key) != string::npos);
			bool keyInAuthor = (author.find(key) != string::npos);
			bool keyInGenre = (genre.find(key) != string::npos);

			if (keyInTitle || keyInISBN || keyInPubName || keyInAuthor || keyInGenre) {
				results.addBook(tempB);
			}
			temp = temp->next;
		}
	}
}

//Returns the string value of a given double
string BookLinkedList::doubleToString(double num) {
	stringstream ss;
	string str;
	ss << num;
	ss >> str;
	return str;
}