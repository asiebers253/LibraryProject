#include "Menus.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include "UserFile.h"
using namespace std;

//generally things are working as expected, but the code needs to be cleaned up a bit

//functions for logging in and for creating a new user seem to work, but the how it prints out should be cleaned up

Menus::Menus() {
	//cout << "in menus" << endl;
	UserFile uf;
	users = uf.loadUsers();
	//users.printAllUsers();
	//users.getUserAt(2).print();
	main();
	//uf.saveUsers(users);
}

void Menus::searchUsers() {
	menuName("User Search Menu");
	UserLinkedList results;
	vector<string> options{ "Search by name", "Search by address", "Search by phone number", "Search by email", "Search by keyword", "Exit" };
	printOptions(options);
	int choice = getInput();
	while (choice == 0) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice == -1) {
		return;
	}
	
	cout << " What would you like to search for?" << endl;
	string input;
	cin >> input;
	cout << endl;

	switch (choice) {
	case 1:
		results = users.searchByName(input);
		break;
	case 2:
		results = users.searchByAddress(input);
		break;
	case 3:
		results = users.searchByPhoneNumber(input);
		break;
	case 4:
		results = users.searchByEmail(input);
		break;
	case 5:
		results = users.searchByKeyword(input);
		break;
	}

	cout << endl;
	//add a thing where if empty, don't run look at search
	lookAtUserSearchResults(results);
}

void Menus::lookAtUserSearchResults(UserLinkedList results) {
	cout << "Which user would you like to look at?" << endl;
	int choice = getInput();
	while (choice == 0) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice == -1) {
		return;
	}
	cout << endl;
	//make error-proof later
	User u = results.getUserAt(choice);
	viewUser(u);
}

void Menus::viewUser(User u) {
	u.print();

	cout << "Would you like to change any of this information?" << endl;
	//NOT DONE YET - put in stuff so admins can make changes to an individual's account
	vector<string> options{ "Manage User's Borrowed Books", "Delete User", "Exit" };
	printOptions(options);
}




//This is the starting menu for the program
//This gives the user the option to login, create a user account, or exit the program
void Menus::main() {
	setupMain();
	string firstName, lastName, address;
	int choice = getInput();

	while (choice != -1) {
		switch (choice) {
		case 1:
			//Bring the user to the login menu
			login();
			break;
		case 2:
			//Bring the user to the register menu
			createUser();
			break;
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			choice = getInput();
			break;
		}
		//If the user is returning from a different menu, re-print the menu
		if (choice == 1 || choice == 2) {
			setupMain();
			choice = getInput();
		}
	}
	//If the user input a -1, exit the system
	cout << "Thank you for using the Cofrin Library System!";
	cout << endl;
}

//Returns a string input
string Menus::getString(string question) {
	string str;
	cout << " " << question << " ";
	cin >> str;
	cout << endl;
	return str;
}

//Returns a int input
int Menus::getInt(string question) {
	string strNum;
	int num;
	cout << " " << question << " ";
	cin >> strNum;
	num = strToInt(strNum);
}

//Prints out the current info for a user that is being created
void Menus::printCheckInfo(string fn, string ln, string a, string pN, string e, string p, int id, bool donor) {
	cout << " Is this information correct?" << endl;
	cout << " First Name: " << fn << "   Last Name: " << ln << endl;
	cout << " Address: " << a << endl;
	cout << " Phone Number: " << pN << endl;;
	cout << " Email: " << e << endl;
	cout << " Institution ID: " << id << endl;
	cout << " Donor: ";
	if (donor == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << "Password: " << p << endl;
}

//Takes input from the user and create a new user account
//Are you a student or an employee?
void Menus::createUser() {
	User u;
	string firstName, lastName, address, phoneNumber, email, password, strInstID = "-1", strDonorStatus;
	int instID;
	bool donorStatus;
	
	//Print out the title information
	menuName("Create User Account");
	cout << " At any time, you can enter -1 to go back to the main menu." << endl;
	cout << endl;
	
	//Get all of the needed information from the user to make a new account
	firstName = getString("What is your first name?");
	if (firstName == "-1") { return; }
	lastName = getString("What is your last name?");
	if (lastName == "-1") { return; }
	cin.ignore(); //clears cin so that getline works properly
	cout << " What is your address? " << endl;
	getline(cin, address);
	cout << endl;
	if (address == "-1") { return; }
	phoneNumber = getString("What is your phone number?");
	if (phoneNumber == "-1") { return; }
	email = getString("What is your email?");
	if (email == "-1") { return; }
	password = getString("What will your password be?");
	if (password == "-1") { return; }
	instID = getInt("What is your institution ID?");
	if (instID == -1) { return; }
	if (instID == 0) {
		cout << "Please enter a valid ID" << endl;
		cin >> strInstID;
		if (strInstID == "-1") { return; }
		instID = strToInt(strInstID);
	}
	cout << endl;
	cout << " Have you donated any books to this library? ";
	cin >> strDonorStatus;
	if (strDonorStatus == "-1") {
		return;
	}
	else if (strDonorStatus == "Yes" || strDonorStatus == "yes") {
		donorStatus = true;
	}
	else {
		donorStatus = false;
	}
	cout << endl;

	printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus);

	vector<string> options{ "Yes", "No", "Exit" };
	vector<string> changeOptions{ "First Name", "Last Name", "Address", "Phone Number", "Email", "Password", "Institution ID", "Donor Status", "Exit" };
	int username;
	printOptions(options);
	int outerChoice = getInput(), innerChoice = 0;


	//add thing to exit to the outer cases
	while (outerChoice != -1) {
		switch (outerChoice) {
		case 1:
			//User u();
			//users.addUser(u);
			username = users.generateLibraryID();
			cout << "Thank you for making an account!" << endl;
			cout << "Please remember the following information in order to login" << endl;
			cout << "Username: " << username << endl;
			cout << "Password: " << password << endl;
			return;
		case 2:
			cout << "What would you like to change?" << endl;
			printOptions(changeOptions);
			innerChoice = getInput();

			while (innerChoice != -1) {
				switch (innerChoice) {
				case 1:
					firstName = getString("What is your first name?");
					if (firstName == "-1") { innerChoice = -1; }
					break;

				case 2:
					lastName = getString("What is your last name?");
					if (lastName == "-1") { innerChoice = -1; }
					break;
				case 3:
					cin.ignore(); //clears cin so that getline works properly
					cout << " What is your address? " << endl;
					getline(cin, address);
					cout << endl;
					if (address == "-1") { innerChoice = -1; }
					break;
				case 4:
					cout << " What is your phone number? ";
					cin >> phoneNumber;
					if (phoneNumber == "-1") { innerChoice = -1; }
					cout << endl;
					break;
				case 5:
					email = getString("What is your email?");
					if (email == "-1") { innerChoice = -1; }
					break;
				case 6:
					password = getString("What will your password be?");
					if (password == "-1") { innerChoice = -1; }
					break;
				case 7:
					instID = getInt("What is your institution ID?");
					if (instID == -1) { innerChoice = -1; }
					if (instID == 0) {
						cout << "Please enter a valid ID" << endl;
						cin >> strInstID;
						if (strInstID == "-1") { innerChoice = -1; }
						instID = strToInt(strInstID);
					}
					cout << endl;
					break;
				case 8:
					cout << " Have you donated any books to this library? ";
					cin >> strDonorStatus;
					if (strDonorStatus == "-1") {
						innerChoice = -1;
					}
					else if (strDonorStatus == "Yes" || strDonorStatus == "yes") {
						donorStatus = true;
					}
					else {
						donorStatus = false;
					}
					cout << endl;
					break;
				}
				if (innerChoice != -1) {
				cout << "Is there anything else you would like to change?" << endl;
				printOptions(changeOptions);
				innerChoice = getInput();
				}
			}

			break;
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			outerChoice = getInput();
		}
		
		printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus);
		printOptions(options);
		outerChoice = getInput();
	}

}

//Sets up the title and options for the main menu
//Also gets what option the user would like to select
void Menus::setupMain() {
	vector<string> options{ "Login", "Create Account", "Exit" };
	menuName("Welcome to the Cofrin Library!");
	printOptions(options);
}

//Gets the choice the user made
int Menus::getInput() {
	string str;
	cin >> str;
	return strToInt(str);
}

//Turns a given string into a int
int Menus::strToInt(string str) {
	stringstream ss;
	int value = 0;
	ss << str;
	ss >> value;
	return value;
}

//Prints all of the options in a given string vector
void Menus::printOptions(vector<string> options) {
	for (int i = 0; i < options.size(); i++) {
		if (options.at(i) == "Exit") {
			cout << " [-1] Exit" << endl;
		} else {
			cout << " [" << i + 1 << "] " << options.at(i) << endl;
		}
	}
}

//Prints the name of a menu
void Menus::menuName(string name) {
	cout << endl;
	cout << " " << name << endl;
	cout << setw(40) << setfill('~') << ""  << setfill(' ') << endl;
}

//Allows the user to log in
//WORKS but may modify
void Menus::login() {
	int username;
	string password, strUsername;
	bool loginSucessful;

	menuName("Login Menu");
	cout << " At any time, you can enter -1 to go back to the main menu." << endl;
	cout << endl;
	
	//User enters a valid username & password
	username = getInt("What is your username?");
	if (username == 0) {
		cout << "Please enter a valid ID" << endl;
		cin >> strUsername;
		if (strUsername == "-1") { return; }
		username = strToInt(strUsername);
	}
	if (username == -1) { return; }

	cout << endl;
	password = getString("What is your password?");
	if (password == "-1") { return; }

	//Check if the username and password match a user in the users UserLinkedList
	loginSucessful = users.isValidLogin(username, password);
	//While login is not sucessful
	while (!loginSucessful) {
		cout << "The username and/or password you entered is not valid." << endl;
		cout << endl;
		username = getInt("What is your username?");
		if (username == -1) { return; }
		if (username == 0) {
			cout << "Please enter a valid ID" << endl;
			cin >> strUsername;
			if (strUsername == "-1") { return; }
			username = strToInt(strUsername);
		}
		cout << endl;
		password = getString("What is your password?");
		if (password == "-1") { return; }
		loginSucessful = users.isValidLogin(username, password);
	}

	//Login was sucessful
	adminMain(username);
}

void Menus::adminMain(int username) {
	string name = users.getUser(username).getFirstName();
	
	menuName("Welcome " + name + "!");

	vector<string> options{"Search Users", "Exit"};
	printOptions(options);
	int choice = getInput();
	while (choice == 0) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice == -1) {
		return;
	}
	while (choice != -1) {
		switch (choice) {
		case 1:
			searchUsers();
			break;
		}
		menuName("Welcome " + name + "!");
		printOptions(options);
		int choice = getInput();
	}
}