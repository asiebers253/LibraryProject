//Made by Alanna Siebers
#pragma once
#ifndef PublisherNode_H
#define PublisherNode_H
#include "Publisher.h"

class PublisherNode {
public:
	Publisher data;
	PublisherNode* next;
};

#endif