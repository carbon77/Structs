#pragma once

#include "BookCard.h"

const int N = 100;

struct StaticTable
{
	int capacity = N;
	int size = 0;
	BookCard data[N];
};

void testStaticArray();