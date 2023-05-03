//Made by Alanna Siebers
#pragma once
#ifndef NewspaperNode_H
#define NewspaperNode_H

#include "Newspapers.h"

class NewspaperNode
{
public:
	Newspapers data;
	NewspaperNode* next;
};

#endif