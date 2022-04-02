#pragma once

#include "BookCard.h"

struct DynamicTable
{
	int size;
	int capacity;
	BookCard* data;
};

void testDynamicArray();