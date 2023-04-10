#include <iostream>
#include "Menus.h"
#include "User.h"
#include "Users.h"
using namespace std;

void testMenu() {
	Menus m;
	m.startMenu();
}

void userSearchTest() {
	Users users;

	User Abby("Abby", "Stout", "1414 Someplace Lane", "920-123-4567", "stoua98@uwgb.edu", "password", 12345678, 87654321, false, true);
	User Brent("Brent", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true, false);
	User Rebecca("Rebecca", "Davis", "1093 Hillside Drive", "920-827-0293", "davir22@uwgb.edu", "paswordpassword", 92830231, 98742039, false, false);

	users.addUser(Abby);
	users.addUser(Brent);
	users.addUser(Rebecca);

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

int main() {
	//testMenu();
	userSearchTest();
}
	