#include "Menus.h"
#include <iostream>
using namespace std;

Menus::Menus() {}

void Menus::startMenu() {
	cout << "Welcome to the Cofrin Library!" << endl;
	cout << "Type in what option you would like to select";
	cout << "[1] Login" << endl;
	cout << "[2] Create Account" << endl;

	cout << "[-1] Exit" << endl;

	cin >> option;
	
	if (option == 1) {

	} else {
		cout << endl;
		cout << "Please choose one of the avaliable options.";
		cout << endl;
		cin >> option;
	}
	
}