#pragma once
#ifndef MENUS_H
#define MENUS_H
#endif

class Menus {
private:
	int option;
public: 
	Menus();
	void startMenu();
	void loginMenu();
	void createUserMenu();
	void guestMenu();
	void userMenu();
	void adminMenu();
	void searchMenu();
	void bookInfoMenu();
	void userInfoMenu();
};

