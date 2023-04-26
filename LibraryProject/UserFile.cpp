#include "UserFile.h"
#include "UserLinkedList.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Books.h"
#include <vector>
#include "Student.h"
#include "Employee.h"
#include "User.h"
using namespace std;

//tack on something at the end of the each user to determine if they are a student or employee


//add something to add individual users to the file
//add something to modify a value in the user file
//same with book id stuff


//Will Be Modified Later!
//Runs all of the functions needed to load all of the user information from various files
UserLinkedList UserFile::loadUsers() {
	UserLinkedList incompleteUsers = readUserFile();
	//UserLinkedList users = readBorrowedBookIDsFile(incompleteUsers);  //need other function to be created in order to use
	//UserLinkedList users = readBookSample(incompleteUsers); //for testing purposes
	return incompleteUsers;
}

//Will be Modifed Later!
//Runs all of the functions needed to save all of the user information into various files
void UserFile::saveUsers(UserLinkedList users) {
	//storeUsers(users);  //storeUsers is working, but storeBookIDs is not
	storeBookIDs(users);
}

//reads the information in the ListOfUsers.txt file and fills a UserLinkedList with the users
UserLinkedList UserFile::readUserFile() {
	fstream fs;
	UserLinkedList users;
	string userInfo;
	int num, pos = 0, prevPos = 0, counter = 1;
	string info;

	fs.open("ListOfUsers.txt");
	if (!fs.is_open()) {
		cout << "ERROR - could not open ListOfUsers.txt file" << endl;
		return users;
	}

	//ListOfUsers has the following format for each line
	//firstName, lastName, address, phoneNumber, email, password, instructionID, libraryID, isDonor, type

	//COMMENT OUT STUFF THAT PRINTS OUT

	while (!fs.eof()) {
		getline(fs, userInfo);
		cout << userInfo << endl;
		pos = 0;
		prevPos = 0;
		info = "";
		counter = 1;
		if (userInfo != "End of File") {
			pos = userInfo.find(",");
			cout << "First pos: " << pos << endl;
			string fn = userInfo.substr(0, pos);
			cout << fn << endl;
			//if (fn != "") {
				string ln, a, pN, e, p, type;
				int id, lid;
				bool donor = false;

				while (counter <= 9) {
					//Get the info
					counter++;
					prevPos = pos;
					pos = userInfo.find(",", prevPos + 1);
					info = userInfo.substr(prevPos + 2, pos - (prevPos + 2));

					cout << info << endl;

					//Get the information needed to make the user object
					if (counter == 2) {
						ln = info;
					}
					else if (counter == 3) {
						a = info;
					}
					else if (counter == 4) {
						pN = info;
					}
					else if (counter == 5) {
						e = info;
					}
					else if (counter == 6) {
						p = info;
					}
					else if (counter == 7) {
						id = strToInt(info);
					}
					else if (counter == 8) {
						lid = strToInt(info);
					}
					else if (counter == 9) {
						if (info == "Yes" || info == "yes") {
							donor = true;
						}
					}
					else {
						type = info;
					}

					//cout << p << " " << id << " " << lid << endl;

				}

				//Create the user and add them to the UserLinkedList
				if (type == "Student") {
					Student st(fn, ln, a, pN, e, p, id, lid, donor);
					users.addUser(st);
					//users.printUserAt(1);
				}
				else {
					Employee em(fn, ln, a, pN, e, p, id, lid, donor);
					users.addUser(em);
				}
				//u.printUserInfo(); //for testing purposes
		//	}
		}

	}

	fs.close();

	//users.printAllUsers();  //for testing purposes
	return users;
}
/*
//Will Be Modified Later! (currently does not work)
//can't finish until vector or file of books is created along with a way to search books by iSBN
UserLinkedList UserFile::readBorrowedBookIDsFile(UserLinkedList users) {
	vector<string> bookIDs;

	fstream fs;
	vector<Books> books;
	Books book;
	string input;
	bool stop = false;
	bool first = true;
	string strID;
	int id;
	stringstream ss;
	int currPos = 0;
	int prevPos = 0;
	int counter = 1;
	fs.open("BorrowedBookIDs.txt");
	if (!fs.is_open()) {
		cout << "ERROR - could not open BorrowedBookIDs.txt file" << endl;
	}

	while (!fs.eof() && input != "End of File") {
		getline(fs, input);
		//cout << "Input: " << input << endl;
		books.clear();
		if (input != "End of File") {
			while (currPos != -1 && input != "") {
				if (first) {
					currPos = input.find(" ");
					strID = input.substr(0, currPos);
					first = false;
				}
				else {
					prevPos = currPos;
					currPos = input.find(" ", prevPos + 1);
					//cout << "prevPos: " << prevPos << " currPos: " << currPos << endl;
					strID = input.substr(prevPos + 1, currPos - prevPos);
					ss.clear();
				}
				ss << strID;
				ss >> id;
				//cout << id << endl; //for testing purposes
				//book = //findBookByID(id);
				//books.push_back(book)
			}
			//users.getUserAt(counter).setBorrowedBooks(books);
		}
	}
	return users;
}

//Sample books created to test the loadUsers and saveUsers functions
//Assumes there are four users
UserLinkedList UserFile::readBookSample(UserLinkedList users) {
	UserLinkedList UsersWithBorrowedBooks;
	vector<Books> books;
	
	Books one("Bob Bobbina", "Book One", "Mr. Publisher", 1, 1234, "emailOFMRPUBLISHER", "addressOFMRPUBLISHER", 12.99);
	Books two("Jane Scharkofski", "Book Two", "Penguin Club", 1, 5432, "wel0vepenguins<3", "Antarctic", 14.59);
	Books three("Justin Palco", "Book Three", "Fishing Co.", 2, 9321, "WELOVEBIGBASS@GMAIL.COM", "The Lake", 9.89);

	UserNode* temp = users.getHead();
	int counter = 1;
	while (temp != NULL) {
		User tempU = temp->data;
		counter++;
		temp = temp->next;
	}
	
	int counter2 = 1;
	while (counter2 < counter) {
		User oldUser = users.getUserAt(counter2);
		User u = oldUser;
		if (counter2 == 1) {
			u.borrowBook(one);
			u.borrowBook(two);
			u.borrowBook(three);
		}
		else if (counter2 == 2) {
			u.borrowBook(two);
		}
		else if (counter2 == 4) {
			u.borrowBook(one);
			u.borrowBook(three);
		}

		UsersWithBorrowedBooks.addUser(u);
		counter2++;
	}
	return UsersWithBorrowedBooks;
}
*/
//Store the relevant information from each user in the given UserLinkedList into the ListOfUsers.txt file
//NEEDS TO BE MODIFIED FOR CHANGES WITH USER CLASS
void UserFile::storeUsers(UserLinkedList users) {
	ofstream ofsUser;
	string output;
	string numStr;

	ofsUser.open("ListOfUsers.txt", ios::out);
	if (!ofsUser.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//ListOfUsers has the following format for each line
	//firstName, lastName, address, phoneNumber, email, password, instructionID, libraryID, isDonor

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
			ss << tempU.getID();
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

//Stores the IDs of the books borrowed by the users
void UserFile::storeBookIDs(UserLinkedList users) {
	ofstream ofs;


	ofs.open("BorrowedBookIDs.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}


		UserNode* temp = users.getHead();
		int counter = 1;
		while (temp != NULL) {
			User tempU = temp->data;
			
			string output = "";
			string val = "";
			for (Books b : tempU.getBorrowedBooks()) {
				stringstream ss;
				ss << b.GetISBN();
				ss >> val;
				output += val + " ";
			}
			output = output.substr(0, output.length() - 1);
			//cout << output << endl; //for testing purposes
			ofs << output << endl;
			

			counter++;
			temp = temp->next;
		}
		ofs << "End of File" << endl;
		
		ofs.close();
}

int UserFile::strToInt(string str) {
	stringstream ss;
	int value = 0;
	ss << str;
	ss >> value;
	return value;
}