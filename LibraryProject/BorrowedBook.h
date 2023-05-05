//Made by Alanna Siebers
#pragma once
#ifndef BorrowedBook_H
#define BorrowedBook_H
#include "Inventory.h"

class BorrowedBook {
private:
	Inventory i;
	time_t start = 0;
	int borrowDays = 7;
	int secInDay = 86400;
	double defaultFine = 0.15;
	double higherFine = 0.25;
public:
	//Default Constructor
	BorrowedBook() {}
	//Parametric Constructors
	BorrowedBook(Inventory &i) {
		this->i = i;
		start = time(NULL);
	}
	BorrowedBook(Inventory i, time_t start) {
		this->i = i;
		this->start = start;
	}

	//Return item in the BorrowedBook object
	Inventory getBook() { return i; }

	//Return borrowDays
	int getBorrowDays() {
		return borrowDays;
	}
	
	//Increase the borrowedDays by 7
	void renew() {
		borrowDays += 7;
	}

	//Students are allowed to borrow books for a week at a time
	void setStudentBorrowDays() {
		borrowDays = 7;
	}

	//Employees are allowed to borrow books for 2 weeks at a time
	void setEmployeeBorrowDays() {
		borrowDays = 14;
	}

	//Calculates the fine when a book is returned
	//Assumes the book is returned at the time the function runs
	double calculateFines() {
		double fine = 0.0;
		time_t end = time(NULL);
		int endDays = end / secInDay;
		int startDays = (start / secInDay);
		int daysPassed = endDays - startDays;

		if (daysPassed <= borrowDays) {
			//book was returned before the due date
			return fine;
		}
		else if (daysPassed > borrowDays && daysPassed <= (borrowDays + 7)) {
			//book was returned within 7 days passed the due date
			for (int i = (borrowDays + 1); i <= daysPassed; i++) {
				fine += defaultFine;
			}
		}
		else {
			//book was returned over a week passed the due date
			fine = (defaultFine * 7);
			for (int i = (borrowDays + 8); i < daysPassed; i++) {
				fine += higherFine;
			}
		}
		return fine;
	}
};

#endif