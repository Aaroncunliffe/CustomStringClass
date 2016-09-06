#pragma once
#include <iostream>
#include <string>


class aString
{

private:
    int* array = nullptr;

public:
    aString();
    aString(char* string);
    ~aString();

    int length();
    void OutputString();

    void concatentate(char* string);
    void concatentate(aString string);

    void toUpper();
    void toLower();
    void trim();
    std::string substring(int beginIndex, int length = 0);
    int find(char* targetString);
    int rfind(char* targetString); // From std::string
    char at(int index);

    void push_front(char* c);
    char pop_back();

    // Operator Overload functions
    void operator+=(char* s);
    void operator+=(const aString &s);
    void operator=(const char* s);
    void operator=(const std::string s);

    friend std::ostream& operator<<(std::ostream& os, aString& s);
    friend std::istream& operator>>(std::istream& os, aString& s);

};


//int *array; // declare a pointer of type int.
//array = new int[someSize]; // dynamically allocate memory using new

//delete[]array; // Delete after use

