#ifndef MISCELLANEOUS_H // Include guards to prevent multiple inclusion
#define MISCELLANEOUS_H

// Include necessary headers
#include "Include.h"

using namespace std;

class Miscellaneous
{
  public:
    Miscellaneous();
    ~Miscellaneous();

    std::string intToString(int);
    std::string getValidString(std::string);
    char getValidChar(const std::string&, const std::vector<char>&);
    int getValidInt(std::string, int, int);
    int getValidInt(std::string);
    std::string titleCase(const std::string&);
};

#endif // MISCELLANEOUS_H
