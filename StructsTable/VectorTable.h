#pragma once

#include <vector>
#include "BookCard.h"

using VectorTable = std::vector<BookCard>;

void testVectorTable();
std::ostream& operator<<(std::ostream& cout, VectorTable& table);
void deleteBookCardsByReturnDate(VectorTable& table, time_t& t);
void deleteBookCardsByReturnDate(VectorTable& table);
int countExpiredBooks(VectorTable& table, time_t t);
int countExpiredBooks(VectorTable& table);