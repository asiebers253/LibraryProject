//Made by Alanna Siebers
#include "ManageFiles.h"
#include "UserLinkedList.h"
#include "PublisherLinkedList.h"
#include "BookLinkedList.h"
#include "JournalLinkedList.h"
#include "NewspaperLinkedList.h"
#include "PeriodicalLinkedList.h"
#include "Books.h"
#include "Student.h"
#include "Employee.h"
#include "Publisher.h"
#include "User.h"
#include "journals.h"
#include "Newspapers.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;


//add something to linkedlists to run append function when needed?
//ADD publishers to all book types along with quantities

//Puts all of the information from the files into the program
void ManageFiles::load(PublisherLinkedList &pub, BookLinkedList &b, JournalLinkedList &j, NewspaperLinkedList &n, PeriodicalLinkedList &per, UserLinkedList &users) {
	b = readBooksFile(pub);
	//j = readJournalsFile();
	//n = readNewspapersFile();
	//per = readPeriodicalsFile();
	//users = readUserFile();
}

//Writes over all of the files with the information currently in the program
void ManageFiles::saveAll(BookLinkedList b, JournalLinkedList j, NewspaperLinkedList n, PeriodicalLinkedList p, UserLinkedList users) {
	saveBookFile(b);
	saveJournalFile(j);
	saveNewspaperFile(n);
	savePeriodicalFile(p);
	saveUserFile(users);
}

//issue with checking publishers...
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
			
			//Create the book and add it to the BookLinkedList
			Books book(author, title, edition, genre, ISBN, price, p);

			books.addBook(book);


			//if (!publishers.find(p)) {
			//	publishers.addPublisher(p);
			//}
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

			char c = institutionalID.at(0);
			if (c == 'S') {
				Student s(firstName, lastName, address, phoneNumber, email, password, institutionalID, libraryID, isDonor);
				users.addUser(s);
			}
			else {
				Employee e(firstName, lastName, address, phoneNumber, email, password, institutionalID, libraryID, isDonor);
				users.addUser(e);
			}
		}
	}
	return users;

	//add borrowed books to each saved user
}



//Stores the relevant information from each user in the given UserLinkedList into the ListOfUsers.txt file
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

//Stores the relevant information from each book in the given BookLinkedList into the books.txt file
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

//Stores the relevant information from each journal in the given JournalLinkedList into the journals.txt file
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

//Stores the relevant information from each Periodical in the given PeriodicalLinkedList into the periodicals.txt file
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

//Stores the relevant information from each Newspaper in the given NewspaperLinkedList into the newspapers.txt file
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

//Stores the IDs of the books borrowed by the users
/*
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


