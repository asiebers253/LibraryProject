//Made by Alanna Siebers
#pragma once
#ifndef UserNode_H
#define UserNode_H

#include "User.h"

class UserNode
{
public:
	User data;
	UserNode* next;
};

#endif