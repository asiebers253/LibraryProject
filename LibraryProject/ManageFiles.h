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
	//Read from the files
	BookLinkedList readBooksFile(PublisherLinkedList& publishers);
	JournalLinkedList readJournalsFile();
	NewspaperLinkedList readNewspapersFile();
	PeriodicalLinkedList readPeriodicalsFile();
	UserLinkedList readUserFile();
	//readborrowedbooks?

	//Other functions
	int strToInt(string str);
	double strToDouble(string str);
	string intToStr(int num);
	string doubleToStr(double d);

public:
	//Load and Save All Data
	void load(PublisherLinkedList& pub, BookLinkedList& b, JournalLinkedList& j, NewspaperLinkedList& n, PeriodicalLinkedList& per, UserLinkedList& users);
	void saveAll(BookLinkedList b, JournalLinkedList j, NewspaperLinkedList n, PeriodicalLinkedList per, UserLinkedList users);

	//Append to the files
	void appendBookFile(Books b);
	void appendJournalFile(Journals j);
	void appendNewspaperFile(Newspapers n);
	void appendPeriodicalFile(Periodicals p);
	void appendUserFile(User u);

	//Write to the files
	void saveBookFile(BookLinkedList books);
	void saveJournalFile(JournalLinkedList journals);
	void saveNewspaperFile(NewspaperLinkedList newspapers);
	void savePeriodicalFile(PeriodicalLinkedList periodicals);
	void saveUserFile(UserLinkedList users);
	//saveborrowedbooks?

};

#endif

//store information constantly as you add the information!
//don't need to make a new class for rewriting individual changes
//but adding a user could user an append funciton