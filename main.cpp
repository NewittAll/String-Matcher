#include <iostream>
#include <string>
#include <stack>

//Prototyping
bool stringCompare(std::string original, std::string input);
int stringCount(std::string original, std::string input);

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string original = "aaabbbaaa";
    std::string input = "bbbaaaaaa";

    stringCompare(original,input);
    return 0;
}

int stringCount(std::string original, std::string input) {
    int count = 0;
    int count1 = 0;

    for(int i = 0; i < original.length(); i++) {
        if(original[i] != input[i]) {
            count++;
        }
        else count = 0;

        if(count > count1) {
            count1 = count;
        }
    }

    return original.length() - count1;
}

bool stringCompare(std::string original, std::string input) {
    std::cout << "Original: ";
    std::cout << original << std::endl;
    std::cout << "Input: ";
    std::cout << input << std::endl;

    int count = stringCount(original,input);
    int i;
    std::stack<char> correctString;
    std::string newString;

    std::cout << "count: ";
    std::cout << count << std::endl;

    if(count == original.length()) {
        std::cout << "True" << std::endl;
        return true;
    }

    for(i = count; i < original.length(); i++) {
        correctString.push(original[i]);
    }
    for(i = 0; i < count; i++) {
        correctString.push(original[i]);
    }
    i = 0;

    while(!correctString.empty()) {
        std::cout << "Top: ";
        std::cout << correctString.top() << std::endl;
        newString[i] = correctString.top();
        std::cout << "New: ";
        std::cout << newString[i] << std::endl;
        correctString.pop();
        i++;
    }

    std::cout << "New: ";
    std::cout << newString << std::endl;
    std::cout << "Input: ";
    std::cout << input << std::endl;

    if(stringCount(newString,input) == original.length()) {
        std::cout << "count: ";
        std::cout << count << std::endl;
        std::cout << "True" << std::endl;
        return true;
    }

    std::cout << "count: ";
    std::cout << count << std::endl;
    std::cout << "False" << std::endl;
    return false;
}