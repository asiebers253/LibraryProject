#pragma once
#ifndef BookNode_H
#define BookNode_H
#include "Books.h"

class BookNode {
public:
	Books data;
	BookNode* next;
};

#endif