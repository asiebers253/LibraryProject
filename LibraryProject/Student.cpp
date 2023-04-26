#include "Student.h"
/*
void Student::print() {
	cout << " User Information - " << firstName << " " << lastName << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Address: " << address << endl;
	cout << " Phone Number: " << phoneNumber << endl;
	cout << " Email: " << email << endl;
	cout << " Student ID: " << studentID << endl;
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
}*/

bool Student::isEqual(Student s) {
	if (studentID == s.getID()) {
		return true;
	}
	else {
		return false;
	}
}
