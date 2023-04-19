#include <iostream>
#include "Menus.h"
#include "UserFile.h"
#include "UserLinkedList.h"
using namespace std;

void testMenu() {
	Menus m;
	m.startMenu();
}

/*
void userSearchTest() {
	UserLinkedList users;

	User Abby("Abby", "Stout", "1414 Someplace Lane", "920-123-4567", "stoua98@uwgb.edu", "password", 12345678, 87654321, false, true);
	User Brent("Brent", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true, false);
	User Rebecca("Rebecca", "Davis", "1093 Hillside Drive", "920-827-0293", "davir22@uwgb.edu", "paswordpassword", 92830231, 98742039, false, false);

	users.addUser(Abby);
	users.addUser(Brent);
	users.addUser(Rebecca);
	
	UserLinkedList results = users.searchByName("Davis");
	User u = results.getUserAt(2);
	cout << endl;
	u.printUserInfo();
	//cout << endl;
	//users.printAllUsers();
	//users.removeUser(Brent);
	//users.searchByName("Davis");
	//cout << endl;
	//users.printAllUsers();
	//User u = users.getUserAt(2);
	

	/*
	users.searchByName("Abby");
	cout << endl;
	users.searchByAddress("1093 Hillside Drive");
	cout << endl;
	users.searchByEmail("stoua98@uwgb.edu");
	cout << endl;
	users.searchByPhoneNumber("920-827-0293");
	cout << endl;
	users.searchByKeyword("Davis");
	
}*/

int main() {
	//Testing readBorrowedBooks
	//UserFile uf;
	//uf.readBorrowedBooks();


	//This works as expected for reading and loading just the basic user information
	/*
	UserFile uf;
	UserLinkedList users = uf.loadUsers();

	User Brent("Rebecca", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true);
	users.addUser(Brent);
	uf.saveUsers(users);
	*/

	/*
	vector<Books> books;
	Books book1("Bob", "THE book", "BestPublisherEver", 2, 1234, "publisher@gmail.com", "1234 address lane", 12.39);
	books.push_back(book1);
	for (Books b : books) {
		cout << b.GetAuthor() << endl;
	}
	

	
	
	Abby.borrowBook(book1);
	//Abby.borrowBook(book1);

	for (Books b : Abby.getBorrowedBooks()) {
		cout << b.GetAuthor() << endl;
	}

	users.addUser(Abby);
	//users.addUser(AbbyA);
	//UserLinkedList search = users.searchByName("Abby");

	for (Books b : users.getUserAt(1).getBorrowedBooks()) {
		cout << b.GetAuthor() << endl;
	}

	//Abby.test();


	//users.addUser(Abby);



	//users.getUserAt(1).test();
	//users.test();
	//uf.storeBookIDs(users);


	/*
	UserFile uf;
	//UserLinkedList users = uf.loadUsers();
	UserLinkedList users;
	vector<Books> test;
	Books book1("Bob", "THE book", "BestPublisherEver", 2, 1234, "publisher@gmail.com", "1234 address lane", 12.39);
	test.push_back(book1);

	User Abby("Abby", "Stout", "1414 Someplace Lane", "920-123-4567", "stoua98@uwgb.edu", "password", 12345678, 87654321, true, test);

	//for some reason, when the vector of books is added to the UserLinkedList, all of the books in the vector vanish
	//might have fixed the issue, but the code isn't done yet
	Books book("Bob Bobbins", "THE FIRST book", "BestPublisherEver", 2, 1029, "publisher@gmail.com", "1234 address lane", 12.39);
	Abby.borrowBook(book);
	users.addUser(Abby);
	users.printAllUsers();
	cout << users.getUserAt(1).getFirstName() << endl;
	for (Books b : users.getUserAt(1).getBorrowedBooks()) {
		cout << b.GetTitle() << endl;
	}

	//uf.storeBookIDs(users);
	*/
}
	