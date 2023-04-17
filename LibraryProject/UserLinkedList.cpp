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

void UserLinkedList::removeNode(User u) {
	if (head == NULL) {
		cout << "No users to remove. " << endl;
	} else {
		UserNode* prevNode = head;
		UserNode* currNode = head->next;
		while (currNode != NULL) {
			User currUser = currNode->data;
			if (currUser.isEqual(u)) {
				prevNode->next = currNode->next;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}

User UserLinkedList::getNodeAt(int index) {
	if (head == NULL) {
		cout << "There are no users." << endl;
		User u;
		return u;
	}
	else {
		UserNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			User tempU = temp->data;
			if (counter == index) {
				return tempU;
			}
			counter++;
			temp = temp->next;
		}
	}
}

UserLinkedList UserLinkedList::printAllUsers() {
	cout << " All Users in the Library System" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	if (head == NULL) {
			cout << "There are no users." << endl;
	} else {
		UserNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			User tempU = temp->data;
			string fn = tempU.getFirstName();
			string ln = tempU.getLastName();
			cout << " [" << counter << "] " << tempU.getFirstName() << " " << tempU.getLastName() << endl;
			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}

//modify to list matches to first or last name first, then the other?
UserLinkedList UserLinkedList::searchByName(string n) {
	UserLinkedList results;
	searchBy(n);

	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;

			//get the user's first and last name
			string fn = tempU.getFirstName();
			string ln = tempU.getLastName();

			//check if the given string is in either the first or last name

			if (fn.find(n) != string::npos|| ln.find(n) != string::npos) {
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

			string email = tempU.getEmail();

			if (email.find(e) != string::npos) {
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

			string address = tempU.getAddress();

			if (address.find(a) != string::npos) {
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

			string phoneNumber = tempU.getPhoneNumber();

			if (phoneNumber.find(pn) != string::npos) {
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