#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;

struct Company
{
	int id;
	std::string name;
};

int forceSearch(std::vector<Company>& arr, int key);
int borderSearch(std::vector<Company>& arr, int key);
int fibSearch(std::vector<Company>& arr, int key);
void testSearch();

