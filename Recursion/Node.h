#pragma once

#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void testReverseLinkedList();
Node* reverse(Node* node);
void push(Node*& node, int newData);
void print(Node* node);

