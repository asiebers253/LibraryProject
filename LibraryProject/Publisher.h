//Made by Alanna Siebers
#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
using namespace std;

class Publisher {
private: 
	string id;
	string publisherName;
	string publisherEmail;
	string publisherAddress;
public:
	Publisher() {};
	Publisher(string publisherName, string publisherEmail, string publisherAddress) {
		this->publisherName = publisherName;
		this->publisherEmail = publisherEmail;
		this->publisherAddress = publisherAddress;
	}
	~Publisher() {};

	string getPublisherName() { return publisherName; }
	string getPublisherEmail() { return publisherEmail; }
	string getPublisherAddress() { return publisherAddress; }
	void setPublisherName(string pn) {
		publisherName = pn;
	}
	void setPublisherEmail(string pe) {
		publisherEmail = pe;
	}
	void setPublisherAddress(string pa) {
		publisherAddress = pa;
	}
	string getID() { return id; };
};

#endif
