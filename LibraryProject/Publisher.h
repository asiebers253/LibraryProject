#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
using namespace std;

class Publisher {
private: 
	string publisherName;
	string publisherEmail;
	string publisherAddress;
public:
	Publisher();
	Publisher(string publisherName, string publisherEmail, string publisherAddress);
	~Publisher();

	string getPublisherName();
	string getPublisherEmail();
	string getPublisherAddress();
	void setPublisherName(string pn);
	void setPublisherEmail(string pe);
	void setPublisherAddress(string pa);
};

#endif
