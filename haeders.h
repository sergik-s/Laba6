#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <cstdint>

constexpr int32_t MAX_EXTRA = 100;
constexpr int32_t MAX_DELIMITERS = 10;

void StringSize(int32_t& size);
void FillString(char* str, int32_t size);
void GetDelimiters(char* delimiters);

void SortDigitLetterElseWords(char* str, char* delimiters);

void PrintString(const char* str);

void DeleteString(char* str);

#endif 
