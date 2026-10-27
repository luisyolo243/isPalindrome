#include <iostream>
#include <string>
#include <cctype> //for std::tolower, so uppercase and lowercase letters count as the same

bool isPalindrome(std::string inputString)
{
    int stringLength = inputString.size();

    //only need to go to the middle of the string, because each pass checks two characters
    for (int index = 0; index < stringLength / 2; ++index)
    {
        char frontCharacter = std::tolower(inputString[index]);
        char backCharacter = std::tolower(inputString[stringLength - 1 - index]);

        if (frontCharacter != backCharacter)
        {
            return false; //found a mismatch, so it can't be a palindrome
        }
    }

    return true; //every pair matched
}

int main()
{
    std::string userInput = "";

    while (userInput != "q")
    {
        std::cout << "Enter a string to check (or q to quit):" << std::endl;
        std::getline(std::cin, userInput);

        if (userInput != "q")
        {
            if (isPalindrome(userInput))
            {
                std::cout << "\"" << userInput << "\" is a palindrome." << std::endl;
            }
            else
            {
                std::cout << "\"" << userInput << "\" is NOT a palindrome." << std::endl;
            }
        }
    }
}