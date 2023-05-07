//Made by Alanna Siebers
#include "ManageFiles.h"
#include "UserLinkedList.h"
#include "PublisherLinkedList.h"
#include "BookLinkedList.h"
#include "JournalLinkedList.h"
#include "NewspaperLinkedList.h"
#include "PeriodicalLinkedList.h"
#include "User.h"
#include "Student.h"
#include "Employee.h"
#include "Publisher.h"
#include "Books.h"
#include "journals.h"
#include "Newspapers.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


/* Load and Save Functions */

//Puts all of the information from the files into the program
void ManageFiles::load(BookLinkedList &b, JournalLinkedList &j, NewspaperLinkedList &n, PeriodicalLinkedList &per, UserLinkedList &users) {
	b = readBooksFile();
	j = readJournalsFile();
	n = readNewspapersFile();
	per = readPeriodicalsFile();
	users = readUserFile(b);
}

//Writes over all of the files with the information currently in the program
void ManageFiles::saveAll(BookLinkedList b, JournalLinkedList j, NewspaperLinkedList n, PeriodicalLinkedList p, UserLinkedList users) {
	saveBookFile(b);
	saveJournalFile(j);
	saveNewspaperFile(n);
	savePeriodicalFile(p);
	saveUserFile(users);
}


/* Read Functions */

//Reads the book information from the "books.txt" file and puts it into a BookLinkedList
BookLinkedList ManageFiles::readBooksFile() {
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
			while (count < 10) {
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

			//Create a publisher 
			Publisher p(pName, pEmail, pAddress);
			
			//Create the book and add it to the BookLinkedList
			Books book(author, title, edition, genre, ISBN, price, p);
			books.addBook(book);
		}
	}
	return books;
}

//Reads the journal information from the "journals.txt" file and puts it into a JournalLinkedList
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

	//File Format: Author, Title, Edition, ISBN, Price, PublisherName, PublisherEmail, PublisherAddress
	string author, title, ISBN, pName, pEmail, pAddress;
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
			while (count < 9) {
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
				case 6:
					pName = chunkOfInfo;
					break;
				case 7:
					pEmail = chunkOfInfo;
					break;
				case 8:
					pAddress = chunkOfInfo;
					break;
				}
				count++;
			}

			//Create a publisher
			Publisher p(pName, pEmail, pAddress);

			//Create a journal and add it to the JournalLinkedList
			Journals j(author, title, edition, ISBN, price, p);
			journals.addJournal(j);
		}
	}
	return journals;
}

//Reads the newspaper information from the "newspapers.txt" file and puts it into a NewspaperLinkedList
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

	//File Format: Title, Date, Frequency, ISBN, price, Publisher Name, Publisher Email, Publisher Address
	string title, date, frequency, ISBN, pName, pEmail, pAddress;
	double price;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {
			title = info.substr(0, currPos);
			while (count < 9) {
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
				case 6:
					pName = chunkOfInfo;
					break;
				case 7:
					pEmail = chunkOfInfo;
					break;
				case 8:
					pAddress = chunkOfInfo;
					break;
				}
				count++;
			}

			//Create a publisher 
			Publisher p(pName, pEmail, pAddress);

			//Create a newspaper and add it to the NewspaperLinkedList
			Newspapers n(title, date, frequency, ISBN, price, p);
			newspapers.add(n);
		}
	}
	return newspapers;
}

//Reads the periodical information from the "periodicals.txt" file and puts it into a PeriodicalLinkedList
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

	//File Format: Title, Date, Frequency, ISBN, price, publisher name, publisher email, publisher address
	string title, date, frequency, ISBN, pName, pEmail, pAddress;
	double price;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		count = 2;

		if (currPos != -1) {
			title = info.substr(0, currPos);
			while (count < 9) {
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
				case 6:
					pName = chunkOfInfo;
					break;
				case 7:
					pEmail = chunkOfInfo;
					break;
				case 8:
					pAddress = chunkOfInfo;
					break;
				}
				count++;
			}

			Publisher p(pName, pEmail, pAddress);

			Periodicals per(title, date, frequency, ISBN, price, p);
			periodicals.addPeriodical(per);

			//Add the publisher to the PublisherLinkedList if it isn't already there
			//if (!publishers.find(p)) {
			//	publishers.addPublisher(p);
			//}
		}
	}
	return periodicals;
}

//Reads the user information from the "ListOfUsers.txt" file and puts it into a UserLinkedList
UserLinkedList ManageFiles::readUserFile(BookLinkedList books) {
	ifstream read;
	UserLinkedList users;
	string info = "", file = "listOfUsers.txt";
	int currPos = -1, prevPos = -1, count = 2;
	int num = 0;
	
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

			//Since reading borrowed books doesn't currently work, this gives users borrowed books
			vector<BorrowedBook> borrowedBooks = sampleBorrowedBooks(books, num);

			char c = institutionalID.at(0);
			if (c == 'S') {
				Student s(firstName, lastName, address, phoneNumber, email, password, institutionalID, libraryID, isDonor, borrowedBooks);
				users.addUser(s);
			}
			else {
				Employee e(firstName, lastName, address, phoneNumber, email, password, institutionalID, libraryID, isDonor, borrowedBooks);
				users.addUser(e);
			}
		}

		num++;
		if (num > 3) {
			num == 1;
		}
	}
	return users;
}

//Returns a vector<BorrowedBook> based on the input
//Assumes there are at least 5 books in the BookLinkedList
vector<BorrowedBook> ManageFiles::sampleBorrowedBooks(BookLinkedList b, int num) {
	BorrowedBook one(b.getAt(3), 1680303600);
	BorrowedBook two(b.getAt(5), 1681686000);
	BorrowedBook three(b.getAt(2), 1677715200);
	BorrowedBook four(b.getAt(1), 1683154800);
	
	vector<BorrowedBook> vOne;
	vector<BorrowedBook> vTwo;
	vector<BorrowedBook> vThree;

	vOne.push_back(one);
	vOne.push_back(three);
	vTwo.push_back(two);
	vThree.push_back(three);
	vThree.push_back(four);

	//if num == 0, user doesn't have any borrowed books

	switch (num) {
	case 1:
		return vOne;
	case 2:
		return vTwo;
	case 3:
		return vThree;
	}
}

//This is an untested, unused function that was intended to read a file of ISBN's and times_t's,
//create BorrowedBook objects based on them, and add those BorrowedBook objects to users
UserLinkedList ManageFiles::readBorrowedBooks(BookLinkedList b, JournalLinkedList j, PeriodicalLinkedList p, NewspaperLinkedList n, UserLinkedList users) {
	ifstream read;
	string info = "", file = "borrowedBooks.txt";
	int currPos = -1, prevPos = -1;

	//Try to open the file
	read.open(file);
	if (!read.is_open()) {
		cout << "Error: Could not open file " << file << endl;
		return users;
	}

	vector<string> ISBNs;
	vector<time_t> times;

	while (!read.eof()) {
		getline(read, info);
		currPos = info.find(",");
		prevPos = -1;
		if (currPos != -1) {
			ISBNs.push_back(info.substr(0, currPos));
			while (currPos != -1) {
			}
		}
		for (int k = 0; k < ISBNs.size(); k++) {
			string ISBN= ISBNs.at(k);
			Books bk = b.get(ISBN);
			Journals jnl = j.getJournal(ISBN);
			Periodicals per = p.getPeriodical(ISBN);
			Newspapers news = n.get(ISBN);
			
			if (bk.GetTitle() != "no match") {
				BorrowedBook book(bk, times.at(k));
			}
			else if (jnl.GetTitle() != "no match") {
				BorrowedBook book(jnl, times.at(k));
			}
			else if (per.GetTitle() != "no match") {
				BorrowedBook book(per, times.at(k));
			}
			else if (news.GetTitle() != "no match") {
				BorrowedBook book(news, times.at(k));
			}
		}
	}
	return users;
}


/* Save Functions */

//Stores the relevant information from each user in the given UserLinkedList into the ListOfUsers.txt file
void ManageFiles::saveUserFile(UserLinkedList users) {
	ofstream ofsUser;
	string output;
	string numStr;

	ofsUser.open("ListOfUsers.txt", ios::out);
	if (!ofsUser.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: firstName, lastName, address, phoneNumber, email, password, institutionID, libraryID, isDonor, publisherName, publisherEmail, publisherAddress

	//store in "ListOfUsers.txt" file
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

	ofs.open("books.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File format: author, title, genre, edition, ISBN, price, publisherName, publisherEmail, publisherAddress

	//store in "book.txt" file
	if (books.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		BookNode* temp = books.getHead();
		while (temp != NULL) {
			Books tempB = temp->data;
			Publisher p = tempB.GetPublisher();

			//Put all of the needed information into a string
			output = tempB.GetAuthor() + ",";
			output += tempB.GetTitle() + ",";
			output += tempB.GetGenre() + ",";
			output += intToStr(tempB.GetEdition()) + ",";
			output += tempB.GetISBN() + ",";
			output += doubleToStr(tempB.GetPrice()) + ",";
			output += p.getPublisherName() + ",";
			output += p.getPublisherEmail() + ",";
			output += p.getPublisherAddress();

			//Put that string into the file
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

	//File Format: author, title, edition, ISBN, price, publisherName, publisherEmail, publisherAddress

	//store in "journals.txt" file
	if (journals.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		JournalNode* temp = journals.getHead();
		while (temp != NULL) {
			Journals tempJ = temp->data;
			Publisher p = tempJ.GetPublisher();
			
			//Put all of the needed information into a string
			output = tempJ.GetAuthor() + ",";
			output += tempJ.GetTitle() + ",";
			output += intToStr(tempJ.GetEdition()) + ",";
			output += tempJ.GetISBN() + ",";
			output += doubleToStr(tempJ.GetPrice()) + ",";
			output += p.getPublisherName() + ",";
			output += p.getPublisherEmail() + ",";
			output += p.getPublisherAddress();
			
			//Put that string into the file
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

	//File Format: title, date, frequency, ISBN, price, publisherName, publisherEmail, publisherAddress

	//store in "periodicals.txt" file
	if (periodicals.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		PeriodicalNode* temp = periodicals.getHead();
		while (temp != NULL) {
			Periodicals tempP = temp->data;
			Publisher p = tempP.GetPublisher();

			//Put all of the needed information into a string
			output += tempP.GetTitle() + ",";
			output += tempP.getDate() + ",";
			output += tempP.getFrequency() + ",";
			output += tempP.GetISBN() + ",";
			output += doubleToStr(tempP.GetPrice()) + ",";
			output += p.getPublisherName() + ",";
			output += p.getPublisherEmail() + ",";
			output += p.getPublisherAddress();

			//Put that string into the file
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

	//File Format: title, date, frequency, ISBN, price, publisherName, publisherEmail, publisherAddress

	//store in "newspapers.txt" file
	if (newspapers.getHead() == NULL) {
		cout << "list is empty." << endl;
		return;
	}
	else {
		NewspaperNode* temp = newspapers.getHead();
		while (temp != NULL) {
			Newspapers tempN = temp->data;
			Publisher p = tempN.GetPublisher();

			//Put all of the needed information into a string
			output += tempN.GetTitle() + ",";
			output += tempN.getDate() + ",";
			output += tempN.getFrequency() + ",";
			output += tempN.GetISBN() + ",";
			output += doubleToStr(tempN.GetPrice()) + ",";
			output += p.getPublisherName() + ",";
			output += p.getPublisherEmail() + ",";
			output += p.getPublisherAddress();

			//Put that string into the file
			ofs << output << endl;
			output = "";
			temp = temp->next;
		}
	}
	ofs.close();
}


/* Append Functions */

//Appends a book's information to the end of the "books.txt" file
void ManageFiles::appendBookFile(Books b) {
	ofstream ofs;
	string output;

	ofs.open("books.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File format: author, title, genre, edition, ISBN, price, publisherName, publisherEmail, publisherAddress

	Publisher p = b.GetPublisher();

	output = b.GetAuthor() + ",";
	output += b.GetTitle() + ",";
	output += b.GetGenre() + ",";
	output += intToStr(b.GetEdition()) + ",";
	output += b.GetISBN() + ",";
	output += doubleToStr(b.GetPrice()) + ",";
	output += p.getPublisherName() + ",";
	output += p.getPublisherEmail() + ",";
	output += p.getPublisherAddress();

	ofs << output << endl;
	ofs.close();
}

//Appends a journal's information to the end of the "journals.txt" file
void ManageFiles::appendJournalFile(Journals j) {
	ofstream ofs;
	string output;

	ofs.open("journals.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Author, Title, Edition, ISBN, Price, Publisher Name, Publisher Email, Publisher Address
	Publisher p = j.GetPublisher();

	output = j.GetAuthor() + ",";
	output += j.GetTitle() + ",";
	output += intToStr(j.GetEdition()) + ",";
	output += j.GetISBN() + ",";
	output += doubleToStr(j.GetPrice()) + ",";
	output += p.getPublisherName() + ",";
	output += p.getPublisherEmail() + ",";
	output += p.getPublisherAddress();

	ofs << output << endl;
	ofs.close();
}

//Appends a Newspaper's information to the end of the "newspapers.txt" file
void ManageFiles::appendNewspaperFile(Newspapers n) {
	ofstream ofs;
	string output;

	ofs.open("newspapers.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: Title, Date, Frequency, ISBN, price
	Publisher p = n.GetPublisher();

	output += n.GetTitle() + ", ";
	output += n.getDate() + ", ";
	output += n.getFrequency() + ", ";
	output += n.GetISBN() + ", ";
	output += doubleToStr(n.GetPrice()) + ",";
	output += p.getPublisherName() + ",";
	output += p.getPublisherEmail() + ",";
	output += p.getPublisherAddress();


	ofs << output << endl;
	ofs.close();
}

//Appends a Periodical's information to the end of the "periodicals.txt" file
void ManageFiles::appendPeriodicalFile(Periodicals p) {
	ofstream ofs;
	string output;

	ofs.open("periodicals.txt", ios::app);
	if (!ofs.is_open()) {
		cout << "File open was not successful" << endl;
	}

	//File Format: title, Date, frequency, ISBN, price, publisherName, publisherEmail, publisherAddress
	Publisher pub = p.GetPublisher();

	output += p.GetTitle() + ", ";
	output += p.getDate() + ", ";
	output += p.getFrequency() + ", ";
	output += p.GetISBN() + ", ";
	output += doubleToStr(p.GetPrice());
	output += pub.getPublisherName() + ",";
	output += pub.getPublisherEmail() + ",";
	output += pub.getPublisherAddress();

	ofs << output << endl;
	ofs.close();
}

//Appends a User's information to the end of the "ListOfUsers.txt" file
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


/* Other Functions */

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