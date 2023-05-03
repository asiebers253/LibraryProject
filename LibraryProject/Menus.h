//Made by Alanna Siebers
#pragma once
#ifndef MENUS_H
#define MENUS_H
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

	void bookSearchResults(BookLinkedList results, int num, User &u);

	void userView(Books b, User& u);
	void userViewOptions(Books b, User& u);

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
	void guestViewPurchase(int quantity);
	
	//Functions accessed by the main function
	void login();
	//void createUser();

	//Functions used by the createUser function
	void printCheckInfo(string fn, string ln, string a, string pN, string e, string p, int id, bool donor, string type);

	//Functions access by the login function
	//void standardUserMenu();
	//void adminMenu();

	void adminMain(User u);
	void searchUsers();
	void lookAtUserSearchResults(UserLinkedList results);
	void viewUser(User u);
	void standardMain(User u);
	
	void guestView(Books b);
	void guestView(Journals j);
	void guestView(Periodicals p);
	void guestView(Newspapers n);

	//void searchBooks();
	//void searchBooksAdmin();

public: 
	Menus();
};

#endif