#include "Menus.h"
#include <iostream>
using namespace std;

Menus::Menus() {}

//change it so it prints options every time
//infinite while loop

void Menus::startMenu() {
	cout << " Welcome to the Cofrin Library!" << endl;
	cout << " (Type in what option you would like to select)" << endl;
	cout << " [1] Login" << endl;
	cout << " [2] Create Account" << endl;
	cout << " [3] Guest Login" << endl;
	cout << " [-1] Exit" << endl;

	cin >> option;

	while (option != 1 && option != 2 && option != 3 && option != -1) {
		cout << endl;
		cout << " Please choose one of the avaliable options.";
		cout << endl;
		cin >> option;
	}
	
	if (option == 1) {
		loginMenu();
	} else if (option == 2) {
		createUserMenu();
	}
	else if (option == 3) {
		guestMenu();
	}
	else if (option == -1) {
		cout << " Thank you for visiting the Cofrin Library!";
		cout << endl;
		exit(0);
	}
}

void Menus::loginMenu() {
	cout << " Login here!" << endl;
	adminMenu();
}

void Menus::createUserMenu() {
	cout << " Create user here!";
}

void Menus::guestMenu() {
	cout << " Guest Menu!";
}

void Menus::userMenu() {
	cout << "User Menu" << endl;
}

void Menus::adminMenu() {
	cout << "Admin Menu" << endl;
	cout << "[1] See User Info" << endl;
	cin >> option;
	if (option == 1) {
		userInfoMenu();
	}
}

void Menus::searchMenu() {
	cout << "Search" << endl;
}

void Menus::bookInfoMenu() {

}

void Menus::userInfoMenu(/*User u*/) {
	//once the user class is added, add info
	cout << endl;
	cout << " User Info" << endl;
	cout << "	First Name: " << endl;
	cout << "	Last Name: " << endl;
	cout << "	Address: " << endl;
	cout << "	Phone Number: " << endl;
	cout << "	Email: " << endl;
	cout << "	Are they a Donor?: " << endl;
	cout << "	Books Currently Borrowed:" << endl;
	//for all borrowed books, print them here

	cout << endl;
	cout << "[1] Edit Borrowing Information" << endl;
	cout << "[2] Modify User Information" << endl;
	cout << "[3] Delete User" << endl;
	cout << "[-1] Back to Search" << endl;

	int num;
	cin >> num;
	if (num == 1) {
		//edit borrowing information menu
	}
	else if (num == 2) {
		//Modify User Information menu
	}
	else if (num == 3) {
		cout << "User "; /* << u.getName() */
		//delete user and return to the search
	}
	else if (num == -1) {
		adminMenu();
	}
	else {
		cout << "try again" << endl;
		cin >> num;
	}
}
