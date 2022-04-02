#pragma once

#include "BookCard.h"

struct DynamicTable
{
	int size;
	int capacity;
	BookCard* data;
};

void testDynamicTable();
void print(DynamicTable& table);
void addBookCard(DynamicTable& table, BookCard& bc);
void removeBookCard(DynamicTable& table, int index);
void deleteBookCardsByReturnDate(DynamicTable& table, time_t& t);
void deleteBookCardsByReturnDate(DynamicTable& table);
int countExpiredBooks(DynamicTable& table, time_t t);
int countExpiredBooks(DynamicTable& table);
