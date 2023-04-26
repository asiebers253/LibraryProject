#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "Publisher.h"
using namespace std;

class Inventory {
public:
	Inventory(Publisher publisher) : publisher(publisher) {}
	Inventory();
	~Inventory();
protected:
	Publisher publisher;
};

#endif
