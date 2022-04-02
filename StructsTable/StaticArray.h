#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <format>

const int N = 100;

struct BookCard
{
	int inventory;
	std::string author;
	std::string name;
	std::tm issueDate;
	std::tm returnDate;
};

struct Table
{
	int capacity = N;
	int size = 0;
	BookCard data[N];
};

void testStaticArray();