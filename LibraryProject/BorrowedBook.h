//Made by Alanna Siebers
#pragma once
#ifndef BorrowedBook_H
#define BorrowedBook_H
#include "Inventory.h"

//FINES WORK
//BORROWING BOOKS WORKS
//add removal of quantity avaliable when borrowing a book?

class BorrowedBook {
private:
	Inventory i;
	time_t start = 0;
	int secInDay = 86400;
	int borrowDays = 7;
	double defaultFine = 0.15;
	double higherFine = 0.25;
public:
	BorrowedBook() {}
	BorrowedBook(Inventory i) {
		this->i = i;
		start = time(NULL);
	}
	BorrowedBook(Inventory i, time_t start) {
		this->i = i;
		this->start = start;
	}
	Inventory getBook() {
		return i;
	}

	double calculateFines() {
		double fine = 0.0;
		time_t end = time(NULL);
		int endDays = end / secInDay;
		int startDays =  (start / secInDay) - 14;  //the - is for testing
		int daysPassed = endDays - startDays;

		if (daysPassed <= borrowDays) {
			return fine;
		}
		else if (daysPassed > borrowDays && daysPassed <= (borrowDays + 7)) {
			for (int i = (borrowDays + 1); i <= daysPassed; i++) {
				fine += defaultFine;
			}
		}
		else {
			fine = (defaultFine * 7);
			for (int i = (borrowDays + 8); i < daysPassed; i++) {
				fine += higherFine;
			}
		}
		return fine;
	}
};

#endif