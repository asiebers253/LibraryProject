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

//BORROWING A BOOK WORKS!!
//add something to prevent borrowing a book multiple times

//Loads the information, runs the program, and saves the information before closing the program
Menus::Menus() {
	//ManageFiles files;
	//files.load(publishers, books, journals, newspapers, periodicals, users);
	//BorrowedBook c;
	User u("Kelly", "stiber", "address", "phone number", "email", "password", "instID", 12345, false);
	Publisher p("Jessica", "pubEmail", "pubAddress");
	Books a("Jane Hainsworth", "To be normal", 1, "informational", "ISBNnum", 12.94, p);
	Books b("author", "title", 1, "genre", "ISBN", 1.99, p);
	books.addBook(a);
	books.addBook(b);
	books.printAllBooks();
	bookSearchResults(books, 2, u);
	cout << "exited bookSearchResults" << endl;
	u.print();
	//u.borrowBook(a);
	//u.borrowBook(b);
	//u.print();
	//u.returnBook(a);
	//u.print();
	//books.printAllBooks();
	//bookSearchResults(books, 1);
	//guestView(b);
	//main();
	//files.saveAll(books, journals, newspapers, periodicals, users);
}

//Prints the name of a menu
void Menus::menuName(string name) {
	cout << endl;
	cout << " " << name << endl;
	cout << setw(40) << setfill('~') << "" << setfill(' ') << endl;
}

//works as expected
void Menus::bookSearchResults(BookLinkedList results, int num, User& u) {
	cout << "What book would you like to look at?" << endl;
	int choice = getInput();
	int size = results.getSize();
	Books b;

	while (choice != -1) {
		if (choice <= size && choice != 0) {
			b = results.getAt(choice);
			
			if (num == 1) {
				guestView(b);
			}
			else if (num == 2) {
				userView(b, u);
			}
			else {
				//adminView(b);
			}
			
			cout << endl;
			results.printAllBooks();
			cout << "What book would you like to look at?" << endl;
			choice = getInput();
		}
		else {
			cout << "input was invalid, please use valid number" << endl;
			choice = getInput();
		}
	}
}

void Menus::userView(Books b, User& u) {
	b.print();
	userViewOptions(b, u);
}

void Menus::userViewOptions(Books b, User& u) {
	vector<string> options{ "Borrow", "Purchase One", "Exit" };
	printOptions(options);
	int choice = getInput();
	int quantity = b.getQuantity();

	while (choice != -1) {
		switch (choice) {
		case 1:
			if (quantity > 1) {
				u.borrowBook(b);
				u.print();
			}
			else {
				cout << "Sorry, since the library has to keep one copy, there are no more"
					<< " copies of this that can be borrowed at the moment." << endl;
			}
			choice = -1;
			break;
		case 2:
			if (quantity <= 1) {
				cout << "Sorry, since the library has to keep one copy, there are no more"
					<< " copies of this that can be sold." << endl;
			}
			else {
				cout << "You have purchased this product!" << endl;
				cout << "Thank you for supporting the Cofrin Library!" << endl;
			}
			cout << endl;
			choice = -1;
			break;
		default:
			cout << "Please enter a valid option." << endl;
			choice = getInput();
			break;
		}
	}
}




void Menus::guestView(Books b) {
	b.print();
	guestViewPurchase(b.getQuantity());
}

void Menus::guestView(Journals j) {
	j.print();
	guestViewPurchase(j.getQuantity());
}

void Menus::guestView(Periodicals p) {
	//p.print();
	guestViewPurchase(p.getQuantity());
}

void Menus::guestView(Newspapers n) {
	//n.print();
	guestViewPurchase(n.getQuantity());
}

//works as expected
void Menus::guestViewPurchase(int quantity) {
	vector<string> options{ "Purchase One", "Exit" };
	printOptions(options);
	int choice = getInput();

	while (choice != -1) {
		switch (choice) {
		case 1:
			if (quantity <= 1) {
				cout << "Sorry, since the library has to keep one copy, there are no more"
					<< " copies of this that can be sold." << endl;

			}
			else {
				cout << "You have purchased this product!" << endl;
				cout << "Thank you for supporting the Cofrin Library!" << endl;
			}
			cout << endl;
			choice = -1;
			break;
		default:
			cout << "Please enter a valid option." << endl;
			choice = getInput();
			break;
		}
	}
}


//This is the starting menu for the program
//This gives the user the option to login, create a user account, or exit the program
void Menus::main() {
	menuName("Welcome to the Cofrin Library!");
	vector<string> options{ "Login", "Create Account", "View Books", "Exit" };
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
			//createUser();
			break;
		case 3:
			//Lets a guest user view the books in the library
			//searchInventory();
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
			vector<string> options{ "Login", "Create Account", "View Books", "Exit" };
			printOptions(options);
			choice = getInput();
		}
	}
	//If the user input a -1, exit the program
	cout << "Thank you for using the Cofrin Library System!";
	cout << endl;
}

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
		cout << "Please enter a valid username" << endl;
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
	User u = users.getUser(username);
	char c = u.getInstitutionalID().at(0);
	if (c == 'S') {
		standardMain(u);
	}
	else {
		adminMain(u);
	}
}

void Menus::standardMain(User u) {
	cout << "Made it to standard user menu" << endl;
	cout << endl;
}

//This is the main menu for users with admin authorization
void Menus::adminMain(User u) {
	string name = u.getFirstName();
	menuName("Welcome " + name + "!");

	vector<string> options{ "Search Users", "Exit" };
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
//NEEDS TO BE MODIFIED
void Menus::printCheckInfo(string fn, string ln, string a, string pN, string e, string p, int id, bool donor, string type) {
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
	cout << "User is a " << type << endl;
}

/*
//Takes input from the user and create a new user account
//Are you a student or an employee?
void Menus::createUser() {
	User u;
	string firstName, lastName, address, phoneNumber, email, password, strInstID = "-1", strDonorStatus, type;
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

	type = getString("Are you a student?");
	if (type == "-1") {
		return;
	}
	else if (type == "Yes" || type == "yes") {
		type = "Student";
	}
	else {
		type = "Employee";
	}
	cout << endl;

	//add if student or employee to check info
	printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus, type);

	vector<string> options{ "Yes", "No", "Exit" };
	vector<string> changeOptions{ "First Name", "Last Name", "Address", "Phone Number", "Email", "Password", "Institution ID", "Donor Status", "User Type", "Exit" };
	int username;
	printOptions(options);
	int outerChoice = getInput(), innerChoice = 0;


	//add thing to exit to the outer case
	while (outerChoice != -1) {
		switch (outerChoice) {
		case 1:
			username = users.generateLibraryID();
			if (type == "Student" || type == "student") {
				Student st(firstName, lastName, address, phoneNumber, email, password, instID, username, donorStatus);
				users.addUser(st);
			}
			else {
				Employee em(firstName, lastName, address, phoneNumber, email, password, instID, username, donorStatus);
				users.addUser(em);
			}
			
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
				case 9:
					type = getString("Are you a student?");
					if (type == "-1") {
						return;
					}
					else if (type == "Yes" || type == "yes") {
						type = "Student";
					}
					else {
						type = "Employee";
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

			
		default:
			//The user input an invalid option
			cout << "Please enter a valid option." << endl;
			outerChoice = getInput();
		}
		
		printCheckInfo(firstName, lastName, address, phoneNumber, email, password, instID, donorStatus, type);
		printOptions(options);
		outerChoice = getInput();
	}

}
*/

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








//NOT DONE
/*
void Menus::searchBooks() {
	menuName("Book Search Menu");

	//this would in theory hold all of the book-type object in the program
	vector<Inventory> i;

	vector<string> options{"Search by title", "Search by Author(s)", "Search by publisher", "search by keyword"};
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
*/

//NOT DONE
/*
void Menus::searchBooksAdmin() {
	menuName("Book Search Menu");

	//this would in theory hold all of the book-type object in the program
	vector<Inventory> i;

	vector<string> options{ "Search by title", "Search by author(s)", "Search by publisher", "search by price", "search by keyword" };
	printOptions(options);
	int choice = getInput();
	if (choice == 0) {
		cout << "please put in a valid option" << endl;
		choice = getInput();
	}
	if (choice == -1) {
		return;
	}

	cout << " What would you like to search? ";
	string str;
	cin >> str;

	switch (choice) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	}

}*/