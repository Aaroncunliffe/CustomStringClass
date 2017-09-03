# Custom String Class

A custom string class made using C++, Dynamically allocates memory, implements a lot of the default functions from std::string.
Can be initialized and treated just like a normal std::string in c++

## Overview of basic use
```c++
#include "aString.h"
int main()
{
    aString foo = "bar";
    
    std::cout << test << std::endl;

    return 0;
}
```

## What is implemented:
```c++
    int length();
    void OutputString();
    void concatentate(char* string);
    void concatentate(aString string);
    void toUpper();
    void toLower();
    void trim();
    std::string substring(int beginIndex, int length = 0);
    int find(char* targetString);
    int rfind(char* targetString); 
    char at(int index);
    void push_front(char* c);
    char pop_back();

```

### Operator overloads for:
* += (taking char* and it's own type)
* = (taking char* and std::string) - This allows for easy declaration, see basic use.
* ostream(<<) and istream(>>) 

## Learning:
1. Operator overloading
2. Dynamic memory 


## bigInt - This was a 1 day challenge at university

inside the big int file is a custom way of storing integers that is not constrained by the maximum integer size, there are also functions for basic arithmetic (add, subtract, multiplication, division, modulo). Examples of each use is commented out in the main() function.

The bigInt is very basic and could easily be improved, it does not use classes or dynamic memory allocation.
