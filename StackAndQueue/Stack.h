#pragma once

#include <string>
#include <iostream>
#include "Node.h"

struct Stack
{
	Node* top = nullptr;
	int size = 0;
};

int top(Stack& stack);
void push(Stack& stack, int value);
int pop(Stack& stack);
std::ostream& operator<<(std::ostream& cout, Stack& stack);
int calculatePostfix(std::string exp);
void testTask2();