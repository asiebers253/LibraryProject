#include "Employee.h"
#include "User.h"

Employee::Employee(string fn, string ln, string a, string pN, string e, string p, int ID, int lID, bool donor)
	: User("Employee", fn, ln, a, pN, e, p, lID, donor), employeeID(ID) {};

/*
void Employee::print() {
	cout << " User Information - " << firstName << " " << lastName << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Address: " << address << endl;
	cout << " Phone Number: " << phoneNumber << endl;
	cout << " Email: " << email << endl;
	cout << " Employee ID: " << employeeID << endl;
	cout << " Library ID: " << libraryID << endl;
	cout << " Are they a donator to the library? ";
	if (isDonor) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	if (borrowedBooks.empty()) {
		cout << " This user is not currently borrowing any books." << endl;
	}
	else {
		cout << " Currently borrowed books: " << endl;
		string books = " ";
		for (Books b : borrowedBooks) {
			books += b.GetTitle() + ", ";
		}
		books = books.substr(0, books.length() - 2);
		cout << books << endl;
	}
	cout << endl;
}

bool Employee::isEqual(Employee e) {
	if (employeeID == e.getID()) {
		return true;
	}
	else {
		return false;
	}
}

*/
//assuming all users have different ids, only the ids need to be compared

/*
bool Employee::isEqual(Employee u) {
	bool sN = false, sA = false, sPN = false, sE = false, sP = false, sIID = false, sLID = false, sPER = false, sD = false, sBB = false;

	if (firstName == u.getFirstName() && lastName == u.getLastName()) { sN = true; }
	if (address == u.getAddress()) { sA = true; }
	if (email == u.getEmail()) { sE = true; }
	if (phoneNumber == u.getPhoneNumber()) { sPN = true; }
	if (password == u.getPassword()) { sP = true; }
	if (employeeID == u.getID()) { sIID = true; }
	if (libraryID == u.getLibraryID()) { sLID = true; }
	if (isDonor == u.getIsDonor()) { sD = true; }
	//something to check if books are equal to each other should be added to the book class

	if (sN && sA && sPN && sE && sP && sIID && sLID && sPER && sD) { return true; }
	else { return false; }
}
*/