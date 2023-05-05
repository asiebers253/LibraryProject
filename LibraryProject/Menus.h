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
	//All of the linkedlists used in the program
	UserLinkedList users;
	BookLinkedList books;
	JournalLinkedList journals;
	NewspaperLinkedList newspapers;
	PeriodicalLinkedList periodicals;

	//Starting Menu
	void main();

	//Login-Related Functions
	void login();
	void standardMain(User u);
	void adminMain(User u);

	//Function for Users to Look at Their Borrowed Books
	void viewBorrowedBooks(User &u);

	//Function to Create a New User
	void createUser();

	//Search Inventory
	void searchInventory(int num);

	//Search Books
	void searchBooksGuest();
	void lookAtBookSearchResultsGuest(BookLinkedList results);
	void viewBookGuest(Books b);

	//Search Newspapers
	void searchNewspapers(int num);
	void lookAtNewspaperSearchResults(NewspaperLinkedList results, int num);
	void viewNewspaperGuest(Newspapers n);

	//Search Users
	void searchUsers();
	void lookAtUserSearchResults(UserLinkedList results);
	void viewUser(User u);

	//Other Functions
	void menuName(string name);
	void printOptions(vector<string> options);
	int getInput();
	string getString(string question);
	int getInt(string question);
	string intToStr(int num);
	int strToInt(string str);
	double strToDouble(string str);
	void printCheckInfo(string fn, string ln, string a, string pN, string e, string p, string id, bool donor);

public: 
	//Default Constructor
	Menus();
};

#endif