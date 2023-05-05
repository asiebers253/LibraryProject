//Made by Alanna Siebers
#include "UserLinkedList.h"
#include "UserNode.h"
#include "User.h"
#include <iostream>
#include <vector>
using namespace std;

//Returns the user with the given libraryID from the userLinkedList
User UserLinkedList::getUser(int id) {
	//UserLinkedList results;
	User u;
	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;

			if (id == tempU.getLibraryID()) {
				return tempU;
			}
			temp = temp->next;
		}
		if (counter == 0) {
			return u;
		}
	}
	return u;
}

//Adds a user to the end of the linked list
void UserLinkedList::addUser(User u) {
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
	totalUsers++;
}

//Removes a user from the UserLinkedList
//assumes that all library IDs are unique to each user
void UserLinkedList::removeUser(User u) {
	if (head == NULL) {
		cout << "No users to remove. " << endl;
	} else {
		UserNode* prevNode = head;
		UserNode* currNode = head->next;
		while (currNode != NULL) {
			User currUser = currNode->data;
			if (currUser.getLibraryID() == u.getLibraryID()) {
				prevNode->next = currNode->next;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
		totalUsers--;
	}
}

//Returns the user at a given position in the linked list
User UserLinkedList::getUserAt(int index) {
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

//Prints all of the users in the UserLinkedList
void UserLinkedList::printAllUsers() {
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

//Prints the information from the user at a given position in the linked list
void UserLinkedList::printUserAt(int index) {
	User u = getUserAt(index);
	u.print();
}

//A small function that runs in all search functions
void UserLinkedList::searchBy(string str) {
	cout << " Search results for \"" << str << "\"" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	if (head == NULL) { cout << "There are no users to search." << endl; }
}

//Searches the UserLinkedList for users with the given name
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
				results.addUser(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

//Searches the UserLinkedList for users with the given email
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
				results.addUser(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

//Searches the UserLinkedList for users with the given address
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
				results.addUser(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

//Searches the UserLinkedList for users with the given phone number
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
				results.addUser(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

//Searches the UserLinkedList for users with the given keyword
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
				results.addUser(tempU);
			}
			temp = temp->next;
		}
		if (counter == 0) {
			cout << "There are no users that match your search" << endl;
		}
	}

	return results;
}

//Returns true if login was sucessful (valid) and false if login was unsuccessful (invalid)
bool UserLinkedList::isValidLogin(int ID, string password) {
	if (head == NULL) {
		cout << "There are no users." << endl;
		return false;
	}
	else {
		UserNode* temp = head;
		int counter = 1;
		while (temp != NULL) {
			User tempU = temp->data;
			//Find the user with the same ID
			if (ID == tempU.getLibraryID()) {
				if (password == tempU.getPassword()) {
					return true;
				}
			}
			temp = temp->next;
		}
		return false;
	}
}

//Creates and returns a valid libraryID
int UserLinkedList::generateLibraryID() {
	int id, upperBound, lowerBound;

	do {
		srand((unsigned) time(0));
		upperBound = 50000000;
		lowerBound = 40000000;
		id = ((rand() % (upperBound - lowerBound + 1)) + lowerBound);
	} while (isLibraryIDUsed(id) && id < upperBound && id > lowerBound);

	return id;
}

//Checks if a given LibraryID matches the LibraryID of a user in the UserLinkedList
bool UserLinkedList::isLibraryIDUsed(int id) {
	if (head != NULL) {
		UserNode* temp = head;
		User tempU;
		int counter = 0;
		while (temp != NULL) {
			tempU = temp->data;
			int libraryID = tempU.getLibraryID();

			if (libraryID == id) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	return false;
}
