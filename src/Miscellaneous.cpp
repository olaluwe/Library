#include <Miscellaneous.h>

using namespace std;

// Function to convert a valid string from the user to Titlecase format
std::string Miscellaneous::titleCase(const std::string& str) {
    if (str.empty()) return "";
    std::string result = str;
    result[0] = std::toupper(result[0]);
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

// Convert an integer to string
std::string Miscellaneous::intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string Miscellaneous::getValidString(std::string prompt)
{
    std::string myString;

    do
    {
        std::cout << prompt;
        std::getline(std::cin, myString);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (myString.empty());

    return myString;
}

char Miscellaneous::getValidChar(const std::string& prompt, const std::vector<char>& targetChars) {
    std::string input;

    while (true) { // Use an infinite loop that returns on valid input
        std::cout << prompt;
        std::getline(std::cin, input); // Read the whole line into input

        if (input.length() == 1) {
            char inputChar = std::toupper(input[0]); // Convert to uppercase to simplify comparison

            // Use std::find to search for inputChar in targetChars
            auto it = std::find_if(targetChars.begin(), targetChars.end(), 
                                   [inputChar](char c) { return std::toupper(c) == inputChar; });

            if (it != targetChars.end()) {
                return *it; // Return the valid character from targetChars
            }
        }

        std::cout << "Invalid input. Please try again.\n";
    }
}

int Miscellaneous::getValidInt(std::string prompt, int minValue, int maxValue)
{
    int value;

    do
    {
        std::cout << prompt;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (std::cin.fail() || value < minValue || value > maxValue);

    return value;
}

int Miscellaneous::getValidInt(std::string prompt)
{
    int value;

    do
    {
        std::cout << prompt;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (std::cin.fail());

    return value;
}