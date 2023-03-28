#include "Menus.h"
#include <iostream>
using namespace std;

Menus::Menus() {}

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
		exit(0);
	}
}

void Menus::loginMenu() {
	cout << " Login here!";
}

void Menus::createUserMenu() {
	cout << " Create user here!";
}

void Menus::guestMenu() {
	cout << " Guest Menu!";
}

