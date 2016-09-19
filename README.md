# Custom String Class

A custom string class made in C++, Dynamically allocates memory, Implements a lot of the default functions from std::string.
Can be initialized and treated just like a normal std::string in c++

## Overview of basic use
```c++
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

