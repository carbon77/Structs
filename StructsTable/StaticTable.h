#pragma once

#include "BookCard.h"

const int N = 100;

struct StaticTable
{
	int capacity = N;
	int size = 0;
	BookCard data[N];
};

void testStaticTable();
void print(StaticTable& table);
void addBookCard(StaticTable& table, BookCard& bc);
void removeBookCard(StaticTable& table, int index);
void deleteBookCardsByReturnDate(StaticTable& table, time_t& t);
void deleteBookCardsByReturnDate(StaticTable& table);
int countExpiredBooks(StaticTable& table, time_t t);
int countExpiredBooks(StaticTable& table);
