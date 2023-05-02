#pragma once
#ifndef MENUS_H
#define MENUS_H
#endif
#include "UserLinkedList.h"
#include "BookLinkedList.h"
#include "JournalLinkedList.h"
#include "NewspaperLinkedList.h"
#include "PeriodicalLinkedList.h"
#include "PublisherLinkedList.h"


class Menus {
private:
	UserLinkedList users;
	BookLinkedList books;
	JournalLinkedList journals;
	NewspaperLinkedList newspapers;
	PeriodicalLinkedList periodicals;
	PublisherLinkedList publishers;


	void main();

	//Get various types of input
	int getInput();
	int getInt(string question);
	string getString(string question);
	
	//Other
	void menuName(string name);
	void printOptions(vector<string> options);
	int strToInt(string str);
	void setupMain();
	
	//Functions accessed by the main function
	void login();
	//void createUser();

	//Functions used by the createUser function
	void printCheckInfo(string fn, string ln, string a, string pN, string e, string p, int id, bool donor, string type);

	//Functions access by the login function
	//void standardUserMenu();
	//void adminMenu();

	void adminMain(int username);
	void searchUsers();
	void lookAtUserSearchResults(UserLinkedList results);
	void viewUser(User u);

	//void searchBooks();
	//void searchBooksAdmin();

public: 
	Menus();
};

