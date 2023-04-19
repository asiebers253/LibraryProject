#include "UserFile.h"
#include "UserLinkedList.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Books.h"
#include <vector>
using namespace std;
#pragma warning(disable : 4996) //lets strtok be used

//file of ids to connect the list of borrowed books to the user

//Assumes that all books have been loaded
//might change to ifstream?
//works as expected
UserLinkedList UserFile::readUserFile() {
	fstream fs;
	UserLinkedList users;
	User u;
	u.setIsGuest(false);
	string userInfo;
	int num;
	int counter = 1;
	int pos;
	int prevPos;

	fs.open("ListOfUsers.txt");
	if (!fs.is_open()) {
		cout << "ERROR - could not open ListOfUsers.txt file" << endl;
		return users;
	}

	//ListOfUsers has the following format for each line
	//firstName, lastName, address, phoneNumber, email, password, instructionID, libraryID, isDonor

	while (!fs.eof()) {
		getline(fs, userInfo);
		if (userInfo != "End of File") {
			pos = userInfo.find(",");
			string fn = userInfo.substr(0, pos);
			if (fn != "") {
			u.setFirstName(fn);
			

			while (counter <= 9) {
				//Get the info
				counter++;
				prevPos = pos;
				pos = userInfo.find(",", prevPos + 1);
				string info = userInfo.substr(prevPos + 2, pos - (prevPos + 2));

				//If needed, change the info from a string to an int
				if (counter == 7 || counter == 8) {
					stringstream ss;
					ss << info;
					ss >> num;
				}
				
				//Add the information to the user object
				if (counter == 2) {
					u.setLastName(info);
				}
				else if (counter == 3) {
					u.setAddress(info);
				}
				else if (counter == 4) {
					u.setPhoneNumber(info);
				}
				else if (counter == 5) {
					u.setEmail(info);
				}
				else if (counter == 6) {
					u.setPassword(info);
				}
				else if (counter == 7) {
					u.setInstructionID(num);
					if ((num / 60000000) == 1) {
						u.setIsAdmin(true);
					}
				}
				else if (counter == 8) {
					u.setLibraryID(num);
				}
				else {
					if (info == "Yes" || info == "yes") {
						u.setIsDonor(true);
					}
				}
				
			}
			u.printUserInfo(); //for testing purposes
			users.addUser(u);
			}
		}
		
	}

	fs.close();

	users.printAllUsers();  //for testing purposes
	return users;
	

	
}

//load Ids of borrowed books

//books will be read based on a file of indexes
	//Gets all of the user information except for the borrowed books

//add relevant borrowed books to borrowed array


UserLinkedList UserFile::loadUsers() {
	UserLinkedList users = readUserFile();
	//readBorrowedBooks();

	return users;
}


//NOT DONE YET
//can't finish until vector or file of books is created
void UserFile::readBorrowedBooks() {
	vector<string> bookIDs;

	//getline of id file
	//fill vector
	//get books with those ids and add them to the borrowed book vector in each user
	
	fstream fs;
	vector<Books> books;
	string input;

	fs.open("BorrowedBookIDs.txt");
	if (!fs.is_open()) {
		cout << "ERROR - could not open BorrowedBookIDs.txt file" << endl;
	}
	while (!fs.eof() && input != "End of File") {
		cout << "Made it to While" << endl;
		getline(fs, input);
		cout << "Input: " << input << endl;
		//if (input != "End of File") {
			int pos = input.find(" ");
			string id1 = input.substr(0, pos);
			cout << pos << endl;
			while (pos != -1) {
				pos = input.find(" ", pos+1);
				cout << pos << endl;
				cout << "inner while" << endl;
			}
		//}
	}
}



//set it to rewrite everything after finishing the program


void UserFile::storeUsers(UserLinkedList users) {
	ofstream ofsUser;
	string output;
	string numStr;

	ofsUser.open("ListOfUsers.txt", ios::out);
	if (!ofsUser.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//store in ListOfUsers file
	if (users.getHead() == NULL) {
		cout << "There are no users." << endl;
		return;
	}
	else {
		UserNode* temp = users.getHead();
		while (temp != NULL) {
			User tempU = temp->data;

			output = tempU.getFirstName() + ", ";
			output += tempU.getLastName() + ", ";
			output += tempU.getAddress() + ", ";
			output += tempU.getPhoneNumber() + ", ";
			output += tempU.getEmail() + ", ";
			output += tempU.getPassword() + ", ";

			stringstream ss;
			ss << tempU.getInstructionID();
			ss >> numStr;
			output += numStr + ", ";

			ss.clear();
			ss << tempU.getLibraryID();
			ss >> numStr;
			output += numStr + ", ";

			if (tempU.getIsDonor()) {
				output += "Yes";
			}
			else {
				output += "No";
			}

			ofsUser << output << endl;
			temp = temp->next;
		}
		ofsUser << "End of File" << endl;
	}
	ofsUser.close();
}

void UserFile::storeBookIDs(UserLinkedList users) {
	if (users.getHead() == NULL) {
		cout << "There are no users." << endl;
	}
	else {
		cout << "IN StoreBookIDs" << endl;
		UserNode* temp = users.getHead();
		int counter = 1;
		while (temp != NULL) {
			User tempU = temp->data;
			
			cout << "TEST" << endl;
			vector<Books> bs;
			Books book("Bob Bobbins", "THE FIRST book", "BestPublisherEver", 2, 1029, "publisher@gmail.com", "1234 address lane", 12.39);
			bs.push_back(book);
			for (Books b : bs) {
				cout << b.GetISBN() << endl;
			}

			cout << "BOOKS" << endl;
			vector<Books> bbs = tempU.getBorrowedBooks();
			for (Books b : bbs) {
				cout << b.GetISBN() << endl;
			}

			counter++;
			temp = temp->next;
		}
		cout << endl;
	}
}


/*
void UserFile::storeBookIDs(UserLinkedList users) {
	//Store ID's of each user's borrowed books
	//ofstream ofsBookIDs;
	//string bookIDs;

	cout << "CAT" << endl;
	
	
	/*
	ofsBookIDs.open("BorrowedBookIDs.txt");
	if (!ofsBookIDs.is_open()) {
		cout << "Book ID File open was not successful" << endl;
		return;
	}

	//store book ids in book id file
	if (users.getHead() == NULL) {
		cout << "There are no users." << endl;
		return;
	}
	else {
		UserNode* temp = users.getHead();
		while (temp != NULL) {
			User tempU = temp->data;
			cout << "IN WHILE LOOP" << endl;
			cout << tempU.test() << endl;
			
			//ofsBookIDs << bookIDs << endl;
			temp = temp->next;
		}
		//ofsBookIDs << "End of File" << endl;
	}
	//ofsBookIDs.close();
}*/

//ListOfUsers has the following format for each line
//firstName, lastName, address, phoneNumber, email, password, instructionID, libraryID, isDonor

void UserFile::saveUsers(UserLinkedList users) {
	storeUsers(users);  //storeUsers is working, but storeBookIDs is not
	//storeBookIDs(users);
}