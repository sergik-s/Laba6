#include "string_operations.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstring>

void StringSize(int32_t& size) {
    std::cout << "Input size of a string: ";
    std::cin >> size;
    
    if (!std::cin || size <= 0) {
        throw std::invalid_argument("Incorrect size of string! Try again!");
    }
    
    std::cin.ignore();
}

void FillString(char* str, int32_t size) { 
    std::cout << "Enter the string (up to " << size << " characters): ";
    std::cin.getline(str, size + 1); 
}

void GetDelimiters(char* delimiters, int32_t max_delimiters) {
    std::cout << "Enter delimiter characters (up to " << max_delimiters << "): ";
    std::cin.getline(delimiters, max_delimiters + 1);
}

void PrintString(char* str) {
    std::cout << str << std::endl;
}

void DeleteString(char* str) {
    delete[] str;
}

void SortDigitLetterElseWords(char* str, char* delimiters) {
    char* copy = new char[strlen(str) + 1];
    strcpy(copy, str);
    
    char* digitWords[MAX_EXTRA] = {nullptr};
    char* letterWords[MAX_EXTRA] = {nullptr};
    char* otherWords[MAX_EXTRA] = {nullptr};
    int32_t digitCount = 0; 
    int32_t letterCount = 0;
    int32_t otherCount = 0;

    char* word = strtok(copy, delimiters);
    while (word != nullptr) {
        bool isAllDigits = true;
        bool isAllLetters = true;
        
        for (int i = 0; word[i] != '\0'; ++i) {
            if (word[i] < '0' || word[i] > '9') isAllDigits = false;
            if ((word[i] < 'A' || word[i] > 'Z') && (word[i] < 'a' || word[i] > 'z')) isAllLetters = false;
        }

        if (isAllDigits) {
            if (digitCount >= MAX_EXTRA) {
                delete[] copy;
                throw std::invalid_argument("Too many digit words!");
            }
            digitWords[digitCount++] = word;
        } else if (isAllLetters) {
            if (letterCount >= MAX_EXTRA) {
                delete[] copy;
                throw std::invalid_argument("Too many letter words!");
            }
            letterWords[letterCount++] = word;
        } else {
            if (otherCount >= MAX_EXTRA) {
                delete[] copy;
                throw std::invalid_argument("Too many other words!");
            }
            otherWords[otherCount++] = word;
        }
        
        word = strtok(nullptr, delimiters);
    }

    char* result = new char[strlen(str) + 1];
    *result = '\0';
    int32_t digitIndex = 0; 
    int32_t letterIndex = 0;
    bool placeDigit = true; 

    if (digitCount > 0) {
        strcat(result, digitWords[digitIndex++]);
        placeDigit = false;
    } else if (letterCount > 0) {
        strcat(result, letterWords[letterIndex++]);
        placeDigit = true;
    }

    while (digitIndex < digitCount && letterIndex < letterCount) {
        if (placeDigit) {
            strcat(result, " ");
            strcat(result, digitWords[digitIndex++]);
        } else {
            strcat(result, " ");
            strcat(result, letterWords[letterIndex++]);
        }
        placeDigit = !placeDigit;
    }

    while (digitIndex < digitCount) {
        strcat(result, " ");
        strcat(result, digitWords[digitIndex++]);
    }

    while (letterIndex < letterCount) {
        strcat(result, " ");
        strcat(result, letterWords[letterIndex++]);
    }

    for (int i = 0; i < otherCount; ++i) {
        strcat(result, " ");
        strcat(result, otherWords[i]);
    }

    strcpy(str, result);
    std::cout << "Sorted string is: " << str << std::endl;
    delete[] result;
    delete[] copy;
}
