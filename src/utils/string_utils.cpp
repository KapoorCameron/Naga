#include<string>

#include"string_utils.h"

void trim(std::string& input)
{
    // Trim whitespace in front and back
    size_t start = input.find_first_not_of(" \t"); // sorts through input, finds first character that's not a " " or "\t" (a tab).
    size_t end = input.find_last_not_of(" \t");

    if (start == std::string::npos) // if input is nothing or some combo of space and tab, start (first non-whitespace char) is npos- no position
    {
        input.clear(); 
    }

    else
    {
        input = input.substr(start, end - start + 1); // substring (the string we create) starts on the first non-whitespace character and grabs end - start + 1 characters 
    }
}