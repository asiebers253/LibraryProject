#include <iostream>
#include "Menus.h"
#include "UserFile.h"
#include "UserLinkedList.h"
using namespace std;

void testMenu() {
	Menus m;
	m.startMenu();
}

void testUserSearch() {
	UserLinkedList users;

	User Abby("Abby", "Stout", "1414 Someplace Lane", "920-123-4567", "stoua98@uwgb.edu", "password", 12345678, 87654321, false);
	User Brent("Brent", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true);
	User Rebecca("Rebecca", "Davis", "1093 Hillside Drive", "920-827-0293", "davir22@uwgb.edu", "paswordpassword", 92830231, 98742039, false);

	users.addUser(Abby);
	users.addUser(Brent);
	users.addUser(Rebecca);
	
	UserLinkedList results = users.searchByName("Davis");
	results.printUserAt(2);

	cout << endl;
	users.printAllUsers();
	users.removeUser(Brent);
	users.searchByName("Davis");
	cout << endl;
	users.printAllUsers();
	User u = users.getUserAt(2);
	
	users.searchByName("Abby");
	cout << endl;
	users.searchByAddress("1093 Hillside Drive");
	cout << endl;
	users.searchByEmail("stoua98@uwgb.edu");
	cout << endl;
	users.searchByPhoneNumber("920-827-0293");
	cout << endl;
	users.searchByKeyword("Davis");
	
}

void testLoadAndSave() {
	//This would be used in the menu class
	UserFile uf;
	UserLinkedList users = uf.loadUsers();
	User Rebecca("Rebecca", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true);
	users.addUser(Rebecca);
	uf.saveUsers(users);
}

int main() {
	//testLoadAndSave();
	//testUserSearch();
	//testMenu();
}
	