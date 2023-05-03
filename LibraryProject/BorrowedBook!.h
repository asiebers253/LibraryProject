//Made by Alanna Siebers
/*
#pragma once
#ifndef BorrowedBook!_H
#define BorrowedBook!_H
#include "Inventory.h"
#include "User.h"
#include <chrono>
#include <vector>


class BorrowedBook! {
private:
	Inventory i;
	time_t start = time(NULL);
	// const time_t s = start;
	 int secInDay = 86400;
	 int borrowDays = 7; //days before fines start
	 //int timeBorrowed;
	 double defaultFine = 0.15;
	 double higherFine = 0.25;
	 //vector<BorrowedBook> bb;
	
	//need to test somehow
public:
	/*
	BorrowedBook() { start = time(NULL); }

	BorrowedBook(Inventory i, time_t start, int borrowTime) {
		this->i = i;
		this->start = start;
		//this->borrowTime = borrowTime;
	}

	BorrowedBook(Inventory i) {
		this->i = i;
		start = time(NULL);
	}
	
	BorrowedBook(const BorrowedBook& book) {
		start = book.start;
		//borrowTime = book.borrowTime;
		i = book.i;
	}

	void getTime() {
		start = time(NULL);

		//NOTE - time_t keeps track of the # of seconds since January 1st, 1970
		
		
		
		cout << start << endl;
		int t = start / secInDay;
		cout << t << " days" << endl;
		
		//end = start + secInDay;
		// t = end / secInDay;
		//cout << t << " days" << endl;


		//t = (end / secInDay) - (start / secInDay);
		//cout << t << " days since borrowed" << endl;
		
	}

	Inventory getBook() {
		return i;
	}

	double calculateFines() {
		double fine = 0.0;
		time_t end = time(NULL);
		int endDays = end / secInDay;
		int startDays = start / secInDay;
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

	
	
	//test to borrow books and remove one of the borrowed books
	//WORKS
	

	
	//void studentBorrow(Student s, Books b) {
	//	start = time(NULL);
	//	s.borrowBook(b);
	//}
	
};

#endif*/