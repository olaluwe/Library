#ifndef MISCELLANEOUS_H // Include guards to prevent multiple inclusion
#define MISCELLANEOUS_H

// Include necessary headers
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Miscellaneous
{
  private:
    /* data */
  public:
    Miscellaneous(/* args */);
    ~Miscellaneous();

    std::string intToString(int);
    std::string getValidString(std::string);
    char getValidChar(const std::string&, const std::vector<char>&);
    int getValidInt(std::string, int, int);
    int getValidInt(std::string);
    std::string titleCase(const std::string&);
};

Miscellaneous::Miscellaneous(/* args */)
{
}

Miscellaneous::~Miscellaneous()
{
}

#endif // MISCELLANEOUS_H
