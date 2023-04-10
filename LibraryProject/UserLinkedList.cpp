#include "UserLinkedList.h"
#include <iostream>
using namespace std;
#include "User.h"
#include "UserNode.h"
#include <vector>

void UserLinkedList::addNode(User u) {
	UserNode* newnode = new UserNode();
	newnode->data = u;
	newnode->next = NULL;
	//once you created the first node
	if (head == NULL) {
		head = newnode;
	}
	else {
		UserNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

UserLinkedList UserLinkedList::searchByName(string n) {
	UserLinkedList results;
	searchBy(n);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;
			if (tempU.getFirstName() == n || tempU.getLastName() == n) {
				counter++;
				cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName() << endl;
				results.addNode(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

void UserLinkedList::searchBy(string str) {
	cout << " Search results for " << str << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	if (head == NULL) { cout << "There are no users to search." << endl; }
}

UserLinkedList UserLinkedList::searchByEmail(string e) {
	UserLinkedList results;
	searchBy(e);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;
			if (tempU.getEmail() == e) {
				counter++;
				cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName();
				cout << " (" << tempU.getEmail() << ")" << endl;
				results.addNode(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

UserLinkedList UserLinkedList::searchByAddress(string a) {
	UserLinkedList results;
	searchBy(a);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;
			if (tempU.getAddress() == a) {
				counter++;
				cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName();
				cout << " (" << tempU.getAddress() << ")" << endl;
				results.addNode(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

UserLinkedList UserLinkedList::searchByPhoneNumber(string pn) {
	UserLinkedList results;
	searchBy(pn);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;
			if (tempU.getPhoneNumber() == pn) {
				counter++;
				cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName();
				cout << " (" <<  tempU.getPhoneNumber() << ")" << endl;
				results.addNode(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

UserLinkedList UserLinkedList::searchByKeyword(string key) {
	UserLinkedList results;
	searchBy(key);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;

			//Getting all of the data values from the current node
			string firstName = tempU.getFirstName();
			string lastName = tempU.getLastName();
			string address = tempU.getAddress();
			string email = tempU.getEmail();
			string phoneNumber = tempU.getPhoneNumber();

			//Check if any of the data values have the key
			bool keyInFirstName = (firstName.find(key) != string::npos);
			bool keyInLastName = (lastName.find(key) != string::npos);
			bool keyInAddress = (address.find(key) != string::npos);
			bool keyInEmail = (email.find(key) != string::npos);
			bool keyInPhoneNumber = (phoneNumber.find(key) != string::npos);

			if (keyInFirstName || keyInLastName || keyInAddress || keyInEmail || keyInPhoneNumber) {
				counter++;
				cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName() << endl;
				results.addNode(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}