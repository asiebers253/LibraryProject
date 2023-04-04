#include <iostream>
#include "Menus.h"
#include "User.h"
#include "Users.h"
using namespace std;



void testMenu() {
	Menus m;
	m.startMenu();
}

void userTest() {
	Users users;

	User Abby("Abby", "Stout", "1414 Someplace Lane", "920-123-4567", "stoua98@uwgb.edu", "password", 12345678, 87654321, false, true);
	User Brent("Brent", "Davis", "1093 Hillside Drive", "920-827-0234", "davib24@uwgb.edu", "SECRETpassword", 92837491, 10923475, true, false);

	users.addUser(Abby);
	users.addUser(Brent);
	users.printAllUsers();
}

void userCreationTest() {
	Users users;
	users.registerUser();
}

int main() {
	//testMenu();
	userTest();
}
	