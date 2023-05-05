//Made by Alanna Siebers
#pragma once
#ifndef Userfile_H
#define Userfile_H
#include <vector>
#include "UserLinkedList.h"
#include "PublisherLinkedList.h"
#include "NewspaperLinkedList.h"
#include "JournalLinkedList.h"
#include "PeriodicalLinkedList.h"
#include "BookLinkedList.h"
#include "Books.h"

class ManageFiles {
private:
	//Read Functions
	BookLinkedList readBooksFile();
	JournalLinkedList readJournalsFile();
	NewspaperLinkedList readNewspapersFile();
	PeriodicalLinkedList readPeriodicalsFile();
	UserLinkedList readUserFile(BookLinkedList b);
	UserLinkedList readBorrowedBooks(BookLinkedList b, JournalLinkedList j, PeriodicalLinkedList p, NewspaperLinkedList n, UserLinkedList users);

	//Write Functions
	void saveBookFile(BookLinkedList books);
	void saveJournalFile(JournalLinkedList journals);
	void saveNewspaperFile(NewspaperLinkedList newspapers);
	void savePeriodicalFile(PeriodicalLinkedList periodicals);
	void saveUserFile(UserLinkedList users);

	//Other functions
	int strToInt(string str);
	double strToDouble(string str);
	string intToStr(int num);
	string doubleToStr(double d);
	vector<BorrowedBook> sampleBorrowedBooks(BookLinkedList b, int num);

public:
	//Load and Save Functions
	void load(BookLinkedList& b, JournalLinkedList& j, NewspaperLinkedList& n, PeriodicalLinkedList& per, UserLinkedList& users);
	void saveAll(BookLinkedList b, JournalLinkedList j, NewspaperLinkedList n, PeriodicalLinkedList per, UserLinkedList users);

	//Append Functions
	void appendBookFile(Books b);
	void appendJournalFile(Journals j);
	void appendNewspaperFile(Newspapers n);
	void appendPeriodicalFile(Periodicals p);
	void appendUserFile(User u);
};

#endif