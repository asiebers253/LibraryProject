//Made by Alanna Siebers
#include "Menus.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include "Student.h"
#include "Employee.h"
#include "ManageFiles.h"
#include "BorrowedBook.h"
using namespace std;

//Loads the information from the files, runs the program, and saves the information into the files before closing the program
Menus::Menus() {
	ManageFiles files;
	files.load(books, journals, newspapers, periodicals, users);
	main();
	files.saveAll(books, journals, newspapers, periodicals, users);
}

//This is the starting menu for the program
//This gives the user the option to login, create a user account, or exit the program
void Menus::main() {
	menuName("Welcome to the Cofrin Library!");
	vector<string> options{ "Login", "Create Account", "Search Inventory", "Exit" };
	printOptions(options);
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
		case 3:
			//Lets a guest user view the books in the library
			searchInventory(1);
			break;
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			choice = getInput();
			break;
		}
		//If the user is returning from a different menu, re-print the menu
		if (choice >= 1 && choice <= 3) {
			menuName("Welcome to the Cofrin Library!");
			vector<string> options{ "Login", "Create Account", "Search Inventory", "Exit" };
			printOptions(options);
			choice = getInput();
		}
	}
	//If the user input a -1, exit the program
	cout << "Thank you for using the Cofrin Library System!";
	cout << endl;
}


/* Functions Related to Logging into the System */

//Allows the user to log into the system
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
		cout << " Please enter a proper username (numbers only - use your Library ID)" << endl;
		username = getInput();
	}
	if (username == -1) { return; }

	cout << endl;
	password = getString("What is your password?");
	if (password == "-1") { return; }

	//Check if the username and password match a user in the users UserLinkedList
	loginSucessful = users.isValidLogin(username, password);
	
	//While login is not sucessful, keep asking for the username and password
	while (!loginSucessful) {
		cout << " The username and/or password you entered is not valid." << endl;
		cout << endl;
		username = getInt("What is your username?");
		if (username == 0) {
			cout << " Please enter a proper username (numbers only - use your Library ID)" << endl;
			username = getInput();
		}
		if (username == -1) { return; }
		cout << endl;
		password = getString("What is your password?");
		if (password == "-1") { return; }
		loginSucessful = users.isValidLogin(username, password);
	}

	//Login was sucessful
	User u = users.getUser(username);
	char c = u.getInstitutionalID().at(0);
	if (c == 'S') {
		//Student Login
		standardMain(u);
	}
	else {
		//Employee Login
		adminMain(u);
	}
}

//This is the menu students are brought to after logging in
void Menus::standardMain(User u) {
	string name = u.getFirstName();
	
	menuName("Welcome " + name + "!");
	vector<string> options{ "View Borrowed Books", "Search Inventory", "Exit" };
	printOptions(options);
	int choice = getInput();

	while (choice != -1) {
		switch (choice) {
		case 1:
			//View the books that the user has borrowed
			viewBorrowedBooks(u);
			break;
		case 2:
			//Search inventory
			searchInventory(1);
			break;
		default:
			//User gave an invalid input
			cout << "Please choose one of the previously mentioned options" << endl;
			choice = getInput();
			break;
		}
		//Reprint the menu after returning from a different menu
		if (choice == 1 || choice == 2) {
			menuName("Welcome " + name + "!");
			vector<string> options{ "View Borrowed Books", "Search Inventory", "Exit" };
			printOptions(options);
			choice = getInput();
		}
		
	}
}

//This is the menu employees are brought to after logging in
void Menus::adminMain(User u) {
	string name = u.getFirstName();
	menuName("Welcome " + name + "!");
	vector<string> options{ "View Borrowed Books", "Search Inventory", "Search Users", "Exit" };
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
			//View the books that the user has borrowed
			viewBorrowedBooks(u);
			break;
		case 2:
			//Search inventory
			searchInventory(1);
			break;
		case 3:
			//Search users
			searchUsers();
			break;
		}

		menuName("Welcome " + name + "!");
		printOptions(options);
		choice = getInput();
		while (choice == 0) {
			cout << "please chose a valid option" << endl;
			choice = getInput();
		}
		if (choice == -1) { return; }
	}
}


/* Function for Users to Look at Their Borrowed Books */

void Menus::viewBorrowedBooks(User &u) {
	menuName("Borrowed Books");
	Inventory book;
	vector<BorrowedBook> bb = u.getBorrowedBooks();
	if (bb.empty()) {
		cout << " You currently do not have any borrowed books";
		cout << endl;
		return;
	}
	for (int i = 0; i < bb.size(); i++) {
		book = bb.at(i).getBook();
		cout << " [" << (i + 1) << "] " << book.GetTitle() << endl;
	}
	cout << endl;

	//Incomplete code that was intented to allow users to renew or return borrowed books 
	/*
	cout << " What would you like to do?" << endl;;
	vector<string> options{ "Renew", "Return", "Exit" };
	printOptions(options);

	int choice = getInput();
	while (choice == 0 || choice > 1) {
		cout << " Please choose one of the options above" << endl;
		choice = getInput();
	}
	if (choice == -1) { return; };

	int choiceBook = getInt("For which book?");
	while (choiceBook == 0 || choiceBook > bb.size()) {
		cout << " Please chose one of the books above" << endl;
		choiceBook = getInput();
	}
	if (choiceBook == -1) { return; };

	switch (choice) {
	case 1:
		//Renew the chosen book
		u.getBorrowedBooks().at(choiceBook - 1).renew();
		cout << endl;
		cout << " Renewed Book!" << endl;
		cout << endl;
		break;
	case 2:
		//Return the chosen book
		//Currently not used
		u.returnBook(u.getBorrowedBooks().at(choiceBook - 1).getBook());
		cout << endl;
		cout << " Returned Book!" << endl;
	}
	*/
}


/* Function for Creating New Users */

//Takes input from the user and uses it to create a new user account
void Menus::createUser() {
	User u;
	string firstName, lastName, address, phoneNumber, email, password, instID, strDonorStatus;
	bool donorStatus = false;

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
	cout << " What is your address? ";
	getline(cin, address);
	cout << endl;
	if (address == "-1") { return; }
	phoneNumber = getString("What is your phone number?");
	if (phoneNumber == "-1") { return; }
	email = getString("What is your email?");
	if (email == "-1") { return; }
	password = getString("What will your password be?");
	if (password == "-1") { return; }
	instID = getString("What is your institution ID?");
	if (instID == "-1") { return; }
	cout << " Have you donated any books to this library? ";
	bool status = true;
	while (status) {
		cin >> strDonorStatus;
		//strDonorStatus has to be "Yes", "yes", "No", or "no"
		if (strDonorStatus == "Yes" || strDonorStatus == "yes") {
			donorStatus = true;
			status = false;
		}
		else if (strDonorStatus == "No" || strDonorStatus == "no") {
			donorStatus = false;
			status = false;
		}
		else if (strDonorStatus == "-1") {
			return;
		}
		else {
			cout << " Please type in yes or no" << endl;
		}
	}
	cout << endl;

	//Print out all of the current information
	printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus);

	vector<string> options{ "Yes", "No", "Exit" };
	vector<string> changeOptions{ "First Name", "Last Name", "Address", "Phone Number", "Email", "Password", "Institution ID", "Donor Status", "Exit" };
	int username;
	printOptions(options);
	int outerChoice = getInput(), innerChoice = 0;
	char c;
	cout << endl;

	while (outerChoice != -1) {
		switch (outerChoice) {
		case 1:
			//The user is ready to create their account
			username = users.generateLibraryID();
			c = instID.at(0);
			if (c == 'S') {
				//The user is a student
				Student st(firstName, lastName, address, phoneNumber, email, password, instID, username, donorStatus);
				users.addUser(st);
			}
			else {
				//The user is an employee
				Employee em(firstName, lastName, address, phoneNumber, email, password, instID, username, donorStatus);
				users.addUser(em);
			}

			//Thank the user for making an account and send them back to the main menu
			cout << endl;
			cout << "Thank you for making an account!" << endl;
			cout << "Please remember the following information in order to login" << endl;
			cout << "Username: " << username << endl;
			cout << "Password: " << password << endl;
			return;
		case 2:
			//The user wants to change something with their information
			cout << "What would you like to change?" << endl;
			printOptions(changeOptions);
			innerChoice = getInput();

			if (innerChoice == -1) {
				break;
			}
			while (innerChoice != -1) {
				cout << endl;
				switch (innerChoice) {
				case 1:
					firstName = getString("What is your first name?");
					if (firstName == "-1") { return; };
					break;
				case 2:
					lastName = getString("What is your last name?");
					if (lastName == "-1") { return; }
					break;
				case 3:
					cin.ignore(); //clears cin so that getline works properly
					cout << " What is your address? " << endl;
					getline(cin, address);
					cout << endl;
					if (address == "-1") { return; }
					break;
				case 4:
					cout << " What is your phone number? ";
					cin >> phoneNumber;
					if (phoneNumber == "-1") { return; }
					cout << endl;
					break;
				case 5:
					email = getString("What is your email?");
					if (email == "-1") { return; }
					break;
				case 6:
					password = getString("What will your password be?");
					if (password == "-1") { return; }
					break;
				case 7:
					instID = getString("What is your institution ID?");
					if (instID == "-1") { return; }
					cout << endl;
					break;
				case 8:
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
					break;

				default:
					//The user input an invalid option
					cout << "Please enter a valid option." << endl;
					innerChoice = getInput();
					break;
				}

				//If returning from making a change, reprint the change menu
				if (innerChoice >= 1 && innerChoice <= 8) {
					cout << "Is there anything else you would like to change?" << endl;
					printOptions(changeOptions);
					innerChoice = getInput();
				}
			}
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			outerChoice = getInput();
			break;
		}
		if (outerChoice == 2) {
			//if returning from change menu, reprint the user's current information
			printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus);
			printOptions(options);
			outerChoice = getInput();
		}
	}
}


/* Functions related to searching book - related objects */

//Asks what type of inventory object the user would like to search
void Menus::searchInventory(int num) {
	menuName("Search Inventory");
	cout << " Which would you like to search?" << endl;
	vector<string> options{ "Search Books", "Search Newspapers", "Exit" };
	printOptions(options);
	int choice = getInput();

	while (choice != -1) {
		switch (choice) {
		case 1:
			searchBooksGuest();
			break;
		case 2:
			searchNewspapers(1);
			break;
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			choice = getInput();
			break;
		}
		//If the user is returning from a different menu, re-print the menu
		if (choice >= 1 && choice <= 4) {
			menuName("Search Inventory");
			cout << " Which would you like to search?" << endl;
			vector<string> options{ "Search Books", "Search Newspapers", "Exit" };
			printOptions(options);
			int choice = getInput();
			if (choice == -1) {
				return;
			}
		}
	}
}


/* Functions related to searching books */

void Menus::searchBooksGuest() {
	BookLinkedList results;
	menuName("Search Books");
	string input = getString("What would you like to search?");
	if (input == "-1") {
		return;
	};
	cout << "What would you like to search by?" << endl;
	vector<string> options{ "Search by Title", "Search by Author", "Search by Genre", "Exit" };
	printOptions(options);
	int choice = getInput();

	while (choice != -1) {
		switch (choice) {
		case 1:
			results = books.searchByTitle(input);
			break;
		case 2:
			results = books.searchByAuthor(input);
			break;
		case 3:
			results = books.searchByGenre(input);
			break;
		default:
			cout << "use a valid option" << endl;
			choice = getInput();
			break;
		}
		if (choice > 0 && choice <= 3) {
			lookAtBookSearchResultsGuest(results);

			menuName("Search Books");
			string input = getString("What would you like to search?");
			if (input == "-1") {
				return;
			};
			cout << "What would you like to search by?" << endl;
			vector<string> options{ "Search by Title", "Search by Author", "Exit" };
			printOptions(options);
			choice = getInput();
		}
	}
}

void Menus::lookAtBookSearchResultsGuest(BookLinkedList results) {
	if (results.getHead() == NULL) {
		cout << "There are no books that match your search" << endl;
		return;
	}

	menuName("Search Results");
	results.printAllBooks();
	cout << "Which book would you like to look at?" << endl;
	int choice = getInput();

	if (choice == -1) {
		return;
	}

	while (choice == 0 || choice < -1 || choice > results.getSize()) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice >= 1 && choice <= results.getSize()) {
		Books b = results.getAt(choice);
		Books bb = books.get(b.GetISBN());
		viewBookGuest(bb);
	}
}

void Menus::viewBookGuest(Books b) {
	b.print();
	vector<string> options{ "Purchase One", "Exit" };
	printOptions(options);
	int choice = getInput();
	while (choice != -1 && choice != 1) {
		cout << "Please enter a valid option." << endl;
		choice = getInput();
	}
	if (choice == 1) {
		cout << endl;
		cout << "You have purchased this product!" << endl;
		cout << "Thank you for supporting the Cofrin Library!" << endl;
	}
}


/* Functions related to searching newspapers */

//Searchs all of the newspapers in the NewspaperLinkedList based on the input
void Menus::searchNewspapers(int num) {
	NewspaperLinkedList results;
	menuName("Search Newspapers");
	string input = getString("What would you like to search?");
	if (input.find("-1") != string::npos) {
		return;
	}
	cout << "What would you like to search by?" << endl;
	vector<string> options{ "Search by Title", "Search by Frequency", "Search by ISBN", "Exit" };
	printOptions(options);
	int choice = getInput();


	while (choice != -1) {
		switch (choice) {
		case 1:
			results = newspapers.searchByTitle(input);
			break;
		case 2:
			results = newspapers.searchByFrequency(input);
			break;
		case 3:
			results = newspapers.searchByISBN(input);
			break;
		default:
			//User put in invalid input
			cout << "Please select one of the previously mentioned options" << endl;
			choice = getInput();
			break;
		}

		if (choice > 0 && choice <= 4) {
			//look at search results
			lookAtNewspaperSearchResults(results, num);

			//reprint the menu
			menuName("Search Newspapers");
			string input = getString("What would you like to search?");
			if (input == "-1") {
				return;
			}
			cout << "What would you like to search by?" << endl;
			vector<string> options{ "Search by Title", "Search by Frequency", "Search by ISBN", "Exit" };
			printOptions(options);
			int choice = getInput();
			if (input == "-1") {
				return;
			}
		}
	}
}

//Look at the search results for a search of newspapers
void Menus::lookAtNewspaperSearchResults(NewspaperLinkedList results, int num) {
	if (results.getHead() == NULL) {
		cout << "There are no newspapers that match your search" << endl;
		return;
	}

	menuName("Search Results");
	results.printAll();
	cout << "Which Newspaper would you like to look at?" << endl;
	int choice = getInput();
	if (choice == -1) {
		return;
	}

	while (choice == 0 || choice < -1 || choice > results.getSize()) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice >= 1 && choice <= results.getSize()) {
		//Look at the newspaper at the given index
		Newspapers  n = results.getAt(choice);
		Newspapers nn = newspapers.get(n.GetISBN());
		if (num == 1) {
			viewNewspaperGuest(nn);
		}
		else {
			//viewNewspaper();
		}
	}
}

//Displays information on a specific newspaper and the user's options for it
void Menus::viewNewspaperGuest(Newspapers n) {
	n.print();
	vector<string> options{ "Purchase One", "Exit" };
	printOptions(options);
	int choice = getInput();
	while (choice != -1 && choice != 1) {
		cout << "Please enter a valid option." << endl;
		choice = getInput();
	}
	if (choice == 1) {
		cout << "You have purchased this product!" << endl;
		cout << "Thank you for supporting the Cofrin Library!" << endl;
	}
}


/* Functions related to searching users */

//Searches all of the users in the UserLinkedList based on the input
void Menus::searchUsers() {
	menuName("User Search Menu");
	cout << " What would you like to search?" << endl;
	string input;
	cin >> input;
	cout << endl;
	if (input == "-1") {
		return;
	}

	cout << " What would you like to search by?" << endl;
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
	if (results.getHead() != NULL) {
		lookAtUserSearchResults(results);
	}
}

//Look at the search results for a search of users
void Menus::lookAtUserSearchResults(UserLinkedList results) {
	cout << "Which user would you like to look at?" << endl;
	int choice = getInput();
	while (choice == 0 || choice > results.getTotalUsers()) {
		cout << "please chose a valid option" << endl;
		choice = getInput();
	}
	if (choice == -1) {
		return;
	}
	cout << endl;
	if (choice > 0 && choice <= results.getTotalUsers()) {
		User u = results.getUserAt(choice);
		viewUser(u);
	}
}

//Prints a given user's information
void Menus::viewUser(User u) {
	u.print();

	//Incompleted code for admin abilities related to users
	/*
	cout << "Would you like to change any of this information?" << endl;
	vector<string> options{ "Manage User's Borrowed Books", "Delete User", "Exit" };
	printOptions(options);
	*/
}


/* Other Functions */

//Prints the name of a menu based on a given string
void Menus::menuName(string name) {
	cout << endl;
	cout << " " << name << endl;
	cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
}

//Prints all of the strings in a given string vector
void Menus::printOptions(vector<string> options) {
	for (int i = 0; i < options.size(); i++) {
		if (options.at(i) == "Exit") {
			cout << " [-1] Exit" << endl;
		}
		else {
			cout << " [" << i + 1 << "] " << options.at(i) << endl;
		}
	}
}

//Gets the choice the user made
int Menus::getInput() {
	string str;
	cin >> str;
	return strToInt(str);
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

//Return a string based on a given int
string Menus::intToStr(int num) {
	stringstream ss;
	string str = "";
	ss << num;
	ss >> str;
	return str;
}

//Return a int based on a given string
int Menus::strToInt(string str) {
	stringstream ss;
	int value = 0;
	ss << str;
	ss >> value;
	return value;
}

//Returns a double based on a given string
double Menus::strToDouble(string str) {
	stringstream ss;
	double value = 0.0;
	ss << str;
	ss >> value;
	return value;
}

//Prints out the current info for a user that is being created
void Menus::printCheckInfo(string fn, string ln, string a, string pN, string e, string p, string id, bool donor) {
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
	cout << " Password: " << p << endl;
	cout << endl;
}
