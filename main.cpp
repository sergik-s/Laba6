#include "string_operations.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstring>

int main() {
    int32_t size{};
    
    try {
        StringSize(size);  
        char* str = new char[size + 1]();
        
        FillString(str, size);
        std::cout << "\nOriginal string: ";
        PrintString(str);
        
        char* delimiters = new char[MAX_DELIMITERS + 1]();
        GetDelimiters(delimiters);
       
        SortDigitLetterElseWords(str, delimiters);
        
        DeleteString(str);
        DeleteString(delimiters);
    } 
    catch (std::invalid_argument& e) {
        std::cerr << "Error! " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
