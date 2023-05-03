//Made by Alanna Siebers
#pragma once
#ifndef JournalNode_H
#define JournalNode_H
#include "Journals.h"

class JournalNode {
public:
	Journals data;
	JournalNode* next;
};

#endif