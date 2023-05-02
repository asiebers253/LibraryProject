#include "ManageFiles.h"
#include "UserLinkedList.h"
#include "BookLinkedList.h"
#include "JournalLinkedList.h"
#include "NewspaperLinkedList.h"
#include "PeriodicalLinkedList.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Books.h"
#include <vector>
#include "Student.h"
#include "Employee.h"
#include "Publisher.h"
#include "PublisherLinkedList.h"
#include "User.h"
#include "journals.h"
#include "Newspapers.h"

using namespace std;
//add something to add individual users to the file
//add something to save when data is changed for a user or book
//same with book id stuff

//Everything in this class needs to be tested!


//Puts all of the information from the files into the program
void ManageFiles::load(PublisherLinkedList &pub, BookLinkedList &b, JournalLinkedList &j, NewspaperLinkedList &n, PeriodicalLinkedList &per, UserLinkedList &users) {
	b = readBooksFile(pub);
	j = readJournalsFile();
	n = readNewspapersFile();
	per = readPeriodicalsFile();
	users = readUserFile();
}

//Writes over all of the files with the information currently in the program
void ManageFiles::saveAll(BookLinkedList b, JournalLinkedList j, NewspaperLinkedList n, PeriodicalLinkedList p, UserLinkedList users) {
	saveBookFile(b);
	saveJournalFile(j);
	saveNewspaperFile(n);
	savePeriodicalFile(p);
	saveUserFile(users);
}

BookLinkedList ManageFiles::readBooksFile(PublisherLinkedList &publishers) {
	ifstream read;
	BookLinkedList books;
	string info = "", file = "books.txt";
	int currPos = -1, prevPos = -1, count = 2;

	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return books;
	}

	//File format: Author, Title, Genre, Edition, ISBN, Price, PublisherName, PublisherEmail, PublisherAddress
	int edition;
	double price;
	string author, title, genre, ISBN, pName, pEmail, pAddress;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;
		
		if (currPos != -1) {
			//Get all of the information about the specific book from the file
			author = info.substr(0, currPos);
			while (count < 8) {
				prevPos = currPos;
				currPos = info.find(",", prevPos + 1);
				string chunkOfInfo = info.substr(prevPos + 1, currPos - (prevPos + 1));

				switch (count) {
				case 2:
					title = chunkOfInfo;
					break;
				case 3:
					genre = chunkOfInfo;
					break;
				case 4:
					edition = strToInt(chunkOfInfo);
					break;
				case 5:
					ISBN = chunkOfInfo;
					break;
				case 6:
					price = strToDouble(chunkOfInfo);
					break;
				case 7:
					pName = chunkOfInfo;
					break;
				case 8:
					pEmail = chunkOfInfo;
					break;
				case 9:
					pAddress = chunkOfInfo;
				}
				count++;
			}

			//Add the book's publisher to the PublisherLinkedList if it isn't already there
			Publisher p(pName, pEmail, pAddress);
			if (!publishers.find(p)) {
				publishers.addPublisher(p);
			}
			
			//Create the book and add it to the BookLinkedList
			Books book(author, title, edition, genre, ISBN, price, p);
			books.addBook(book);
		}
	}
	return books;
}

JournalLinkedList ManageFiles::readJournalsFile() {
	ifstream read;
	JournalLinkedList journals;
	string info = "", file = "journals.txt";
	int currPos = -1, prevPos = -1, count = 2;

	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return journals;
	}

	//File Format: Author, Title, Edition, ISBN, Price
	string author, title, ISBN;
	int edition;
	double price;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {

			//Get all of the information about the specific publisher
			author = info.substr(0, currPos);
			while (count < 6) {
				prevPos = currPos;
				currPos = info.find(",", prevPos + 1);
				string chunkOfInfo = info.substr(prevPos + 1, currPos - (prevPos + 1));

				switch (count) {
				case 2:
					title = chunkOfInfo;
					break;
				case 3:
					edition = strToInt(chunkOfInfo);
					break;
				case 4:
					ISBN = chunkOfInfo;
					break;
				case 5:
					price = strToDouble(chunkOfInfo);
					break;
				}
				count++;
			}

			Journals j(author, title, edition, ISBN, price);
			journals.addJournal(j);
		}
	}
	return journals;
}

//Date might be changed if a date class is created
NewspaperLinkedList ManageFiles::readNewspapersFile() {
	ifstream read;
	NewspaperLinkedList newspapers;
	string info = "", file = "newspapers.txt";
	int currPos = -1, prevPos = -1, count = 2;

	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return newspapers;
	}

	//File Format: Title, Date, Frequency, ISBN, price
	string title, date, frequency, ISBN;
	double price;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {
			title = info.substr(0, currPos);
			while (count < 6) {
				prevPos = currPos;
				currPos = info.find(",", prevPos + 1);
				string chunkOfInfo = info.substr(prevPos + 1, currPos - (prevPos + 1));
				switch (count) {
				case 2:
					date = chunkOfInfo;
					break;
				case 3:
					frequency = chunkOfInfo;
					break;
				case 4:
					ISBN = chunkOfInfo;
					break;
				case 5:
					price = strToDouble(chunkOfInfo);
					break;
				}
				count++;
			}

			Newspapers n(title, date, frequency, ISBN, price);
			newspapers.add(n);
		}
	}
	return newspapers;
}

//Date might be changed if a date class is created
PeriodicalLinkedList ManageFiles::readPeriodicalsFile() {
	ifstream read;
	PeriodicalLinkedList periodicals;
	string info = "", file = "periodicals.txt";
	int currPos = -1, prevPos = -1, count = 2;

	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return periodicals;
	}

	//File Format: Title, Date, Frequency, ISBN, price
	string title, date, frequency, ISBN;
	double price;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {
			title = info.substr(0, currPos);
			while (count < 6) {
				prevPos = currPos;
				currPos = info.find(",", prevPos + 1);
				string chunkOfInfo = info.substr(prevPos + 1, currPos - (prevPos + 1));
				switch (count) {
				case 2:
					date = chunkOfInfo;
					break;
				case 3:
					frequency = chunkOfInfo;
					break;
				case 4:
					ISBN = chunkOfInfo;
					break;
				case 5:
					price = strToDouble(chunkOfInfo);
					break;
				}
				count++;
			}

			Periodicals p(title, date, frequency, ISBN, price);
			periodicals.addPeriodical(p);
		}
	}
	return periodicals;
}

//need to add borrowed books to users
UserLinkedList ManageFiles::readUserFile() {
	ifstream read;
	UserLinkedList users;
	string info = "", file = "listOfUsers.txt";
	int currPos = -1, prevPos = -1, count = 2;
	
	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return users;
	}

	//File Format: firstName, lastName, address, phoneNumber, email, password, institutionID, libraryID, isDonor
	string firstName, lastName, address, phoneNumber, email, password, institutionalID;
	int libraryID;
	bool isDonor = false;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {
			firstName = info.substr(0, currPos);
			while (count < 10) {
				prevPos = currPos;
				currPos = info.find(",", prevPos + 1);
				string chunkOfInfo = info.substr(prevPos + 1, currPos - (prevPos + 1));

				switch (count) {
				case 2:
					lastName = chunkOfInfo;
					break;
				case 3:
					address = chunkOfInfo;
					break;
				case 4:
					phoneNumber = chunkOfInfo;
					break;
				case 5:
					email = chunkOfInfo;
					break;
				case 6:
					password = chunkOfInfo;
					break;
				case 7:
					institutionalID = chunkOfInfo;
					break;
				case 8:
					libraryID = strToInt(chunkOfInfo);
					break;
				case 9:
					if (chunkOfInfo == "Yes" || chunkOfInfo == "yes") {
						isDonor = true;
					}
					break;
				}
				count++;
			}

			User u(firstName, lastName, address, phoneNumber, email, password, institutionalID, libraryID, isDonor);
			users.addUser(u);
		}
	}
	return users;

	//add borrowed books to each saved user
}



//Store the relevant information from each user in the given UserLinkedList into the ListOfUsers.txt file
void ManageFiles::saveUserFile(UserLinkedList users) {
	ofstream ofsUser;
	string output;
	string numStr;

	ofsUser.open("ListOfUsers.txt", ios::out);
	if (!ofsUser.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//ListOfUsers has the following format for each line
	//firstName, lastName, address, phoneNumber, email, password, institutionID, libraryID, isDonor

	//store in ListOfUsers file
	if (users.getHead() == NULL) {
		cout << "There are no users." << endl;
		return;
	}
	else {
		UserNode* temp = users.getHead();
		while (temp != NULL) {
			User tempU = temp->data;

			output = tempU.getFirstName() + ",";
			output += tempU.getLastName() + ",";
			output += tempU.getAddress() + ",";
			output += tempU.getPhoneNumber() + ",";
			output += tempU.getEmail() + ",";
			output += tempU.getPassword() + ",";
			output += tempU.getInstitutionalID() + ",";
			output += intToStr(tempU.getLibraryID()) + ",";

			if (tempU.getIsDonor()) {
				output += "Yes";
			}
			else {
				output += "No";
			}

			ofsUser << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofsUser.close();
}

void ManageFiles::saveBookFile(BookLinkedList books) {
	ofstream ofs;
	string output;

	ofs.open("ListOfUsers.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File format: Author, Title, Genre, Edition, ISBN, Price, PublisherName, PublisherEmail, PublisherAddress

	//store in file
	if (books.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		BookNode* temp = books.getHead();
		while (temp != NULL) {
			Books tempB = temp->data;
			Publisher p = tempB.GetPublisher();

			output = tempB.GetAuthor() + ",";
			output += tempB.GetTitle() + ",";
			output += tempB.GetGenre() + ",";
			output += tempB.GetEdition() + ",";
			output += tempB.GetISBN() + ",";
			output += doubleToStr(tempB.GetPrice()) + ",";
			output += p.getPublisherName() + ",";
			output += p.getPublisherEmail() + ",";
			output += p.getPublisherAddress();

			ofs << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofs.close();
}

void ManageFiles::saveJournalFile(JournalLinkedList journals) {
	ofstream ofs;
	string output;

	ofs.open("journals.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Author, Title, Edition, ISBN, Price

	//store in file
	if (journals.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		JournalNode* temp = journals.getHead();
		while (temp != NULL) {
			Journals tempJ = temp->data;
			
			output = tempJ.GetAuthor() + ",";
			output += tempJ.GetTitle() + ",";
			output += intToStr(tempJ.GetEdition()) + ",";
			output += tempJ.GetISBN();
			output += tempJ.GetPrice();

			ofs << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofs.close();
}

void ManageFiles::savePeriodicalFile(PeriodicalLinkedList periodicals) {
	ofstream ofs;
	string output;

	ofs.open("periodicals.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Title, Date, Frequency, ISBN, price

	//store in file
	if (periodicals.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		PeriodicalNode* temp = periodicals.getHead();
		while (temp != NULL) {
			Periodicals tempP = temp->data;

			output += tempP.getTitle() + ",";
			output += tempP.getDate() + ",";
			output += tempP.getFrequency() + ",";
			output += tempP.getISBN() + ",";
			output += doubleToStr(tempP.getPrice());

			ofs << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofs.close();
}

void ManageFiles::saveNewspaperFile(NewspaperLinkedList newspapers) {
	ofstream ofs;
	string output;

	ofs.open("newspapers.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Title, Date, Frequency, ISBN, price

	//store in file
	if (newspapers.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		NewspaperNode* temp = newspapers.getHead();
		while (temp != NULL) {
			Newspapers tempN = temp->data;

			output += tempN.getTitle() + ",";
			output += tempN.getDate() + ",";
			output += tempN.getFrequency() + ",";
			output += tempN.getISBN() + ",";
			output += doubleToStr(tempN.getPrice());

			ofs << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofs.close();
}





void ManageFiles::appendBookFile(Books b) {
	ofstream ofs;
	string output;

	ofs.open("books.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: firstName, lastName, address, phoneNumber, email, password, institutionID, libraryID, isDonor

	Publisher p = b.GetPublisher();

	output = b.GetAuthor() + ", ";
	output += b.GetTitle() + ", ";
	output += b.GetGenre() + ", ";
	output += intToStr(b.GetEdition()) + ", ";
	output += b.GetISBN() + ", ";
	output += doubleToStr(b.GetPrice()) + ", ";
	output += p.getPublisherName() + ", ";
	output += p.getPublisherEmail() + ", ";
	output += p.getPublisherAddress();

	ofs << output << endl;
	ofs.close();
}

void ManageFiles::appendJournalFile(Journals j) {
	ofstream ofs;
	string output;

	ofs.open("journals.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Author, Title, Edition, ISBN, Price

	output = j.GetAuthor() + ", ";
	output += j.GetTitle() + ", ";
	output += intToStr(j.GetEdition()) + ", ";
	output += j.GetISBN() + ", ";
	output += doubleToStr(j.GetPrice());

	ofs << output << endl;
	ofs.close();
}

void ManageFiles::appendNewspaperFile(Newspapers n) {
	ofstream ofs;
	string output;

	ofs.open("newspapers.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Title, Date, Frequency, ISBN, price

	output += n.getTitle() + ", ";
	output += n.getDate() + ", ";
	output += n.getFrequency() + ", ";
	output += n.getISBN() + ", ";
	output += doubleToStr(n.getPrice());

	ofs << output << endl;
	ofs.close();
}

void ManageFiles::appendPeriodicalFile(Periodicals p) {
	ofstream ofs;
	string output;

	ofs.open("periodicals.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Title, Date, Frequency, ISBN, price

	output += p.getTitle() + ", ";
	output += p.getDate() + ", ";
	output += p.getFrequency() + ", ";
	output += p.getISBN() + ", ";
	output += doubleToStr(p.getPrice());

	ofs << output << endl;
	ofs.close();
}

void ManageFiles::appendUserFile(User u) {
	ofstream ofs;
	string output;

	ofs.open("ListOfUsers.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: firstName, lastName, address, phoneNumber, email, password, institutionID, libraryID, isDonor

	output = u.getFirstName() + ", ";
	output += u.getLastName() + ", ";
	output += u.getAddress() + ", ";
	output += u.getPhoneNumber() + ", ";
	output += u.getEmail() + ", ";
	output += u.getPassword() + ", ";
	output += u.getInstitutionalID() + ", ";
	output += intToStr(u.getLibraryID()) + ", ";
	if (u.getIsDonor()) {
		output += "Yes";
	}
	else {
		output += "No";
	}

	ofs << output << endl;
	ofs.close();
}


//Returns a int based on a given string
int ManageFiles::strToInt(string str) {
	stringstream ss;
	int value = 0;
	ss << str;
	ss >> value;
	return value;
}

//Returns a double based on a given string
double ManageFiles::strToDouble(string str) {
	stringstream ss;
	double value = 0.0;
	ss << str;
	ss >> value;
	return value;
}

//Returns a string based on a given int
string ManageFiles::intToStr(int num) {
	stringstream ss;
	string str = "";
	ss << num;
	ss >> str;
	return str;
}

//Returns a string based on a given double
string ManageFiles::doubleToStr(double d) {
	stringstream ss;
	string str = "";
	ss << d;
	ss >> str;
	return str;
}

//Will Be Modified Later!
//Runs all of the functions needed to load all of the user information from various files
/*
UserLinkedList ManageFiles::loadUsers() {
	//UserLinkedList incompleteUsers = readUserFile();
	
	//UserLinkedList users = readBorrowedBookIDsFile(incompleteUsers);  //need other function to be created in order to use
	
	return incompleteUsers;
}

//Will be Modifed Later!
//Runs all of the functions needed to save all of the user information into various files
void ManageFiles::saveUsers(UserLinkedList users) {
	storeUsers(users);  
	//storeBookIDs(users);
}

//reads the information in the ListOfUsers.txt file and fills a UserLinkedList with the users
UserLinkedList ManageFiles::readUserFile() {
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
		//cout << userInfo << endl;
		pos = 0;
		prevPos = 0;
		info = "";
		counter = 1;
		if (userInfo != "End of File") {
			pos = userInfo.find(",");
			//cout << "First pos: " << pos << endl;
			if (pos != -1) {
			string fn = userInfo.substr(0, pos);
			//cout << fn << endl;
			//if (fn != "") {
				string ln, a, pN, e, p, type;
				int id, lid;
				bool donor = false;

				while (counter <= 9) {
					//Get the info
					counter++;
					prevPos = pos;
					pos = userInfo.find(",", prevPos + 1);

					//cout << prevPos << endl;
					//cout << pos << endl;
					//cout << endl;

					//if (counter != 10) {
						info = userInfo.substr(prevPos + 2, pos - (prevPos + 2));
					//}
					//else {
						//info = userInfo.substr(prevPos + 2);
					//}

					//cout << prevPos << endl;
					//cout << pos << endl;
					//cout << endl;
					//cout << info << endl;

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
					//cout << st.getType() << endl;
					//users.printUserAt(1);
				}
				else {
					Employee em(fn, ln, a, pN, e, p, id, lid, donor);
					users.addUser(em);
					//cout << "added an employee user" << endl;
					//cout << em.getType() << endl;
					//cout << users.getUserAt(1).getType() << endl;
				}
				//u.printUserInfo(); //for testing purposes
			}
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


//Store the relevant information from each user in the given UserLinkedList into the ListOfUsers.txt file
//NEEDS TO BE MODIFIED FOR CHANGES WITH USER CLASS
void ManageFiles::storeUsers(UserLinkedList users) {
	ofstream ofsUser;
	string output;
	string numStr;

	ofsUser.open("ListOfUsers.txt", ios::out);
	if (!ofsUser.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//ListOfUsers has the following format for each line
	//firstName, lastName, address, phoneNumber, email, password, instructionID, libraryID, isDonor, type

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
			cout << tempU.getType() << endl;
			output += ", " + tempU.getType();

			ofsUser << output << endl;
			cout << output << endl;
			temp = temp->next;
		}
		ofsUser << "End of File" << endl;
	}
	ofsUser.close();
}

//Stores the IDs of the books borrowed by the users
void ManageFiles::storeBookIDs(UserLinkedList users) {
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
*/