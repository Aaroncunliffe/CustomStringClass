#include "aString.h"

aString::aString()
{

}

aString::aString(char* string)
{
    // Get length of string
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }

    // Allocate memory to the string
    array = new int[i + 1];
    array[0] = i;

    // put string into array
    for (int j = 0; j < array[0]; j++)
    {
        if (string[j] == '\0')
        {
            break;
        }
        array[j + 1] = string[j];
    }


}

aString::~aString()
{

}

int aString::length()
{
    return array[0];
}

void aString::OutputString()
{
    for (int i = 1; i <= array[0]; i++)
    {
        std::cout << (char)array[i];
    }
    std::cout << std::endl;
}

void aString::toUpper()
{
    for (int i = 1; i <= array[0]; i++)
    {
        if (array[i] >= 97 && array[i] <= 122)
        {
            array[i] = array[i] - 32;
        }
    }
}

void aString::toLower()
{
    for (int i = 1; i <= array[0]; i++)
    {
        if (array[i] >= 65 && array[i] <= 90)
        {
            array[i] = array[i] + 32;
        }
    }
}

void aString::trim()
{
    // Check front of the array
    for (int i = 1; i <= array[0]; i++)
    {
        if (array[i] != 32)
        {
            break;
        }
        else if (array[i] == 32) //space
        {
            // Shift characters back
            for (int j = i; j <= array[0] - i; j++)
            {
                array[j] = array[j + 1];
            }
            array[0]--;
            trim(); // Recursive function call
        }
    }

    // Check back of the array and shrink until hitting a character. You don't actually have to change what is in the array, just make the lenght value ignore it
    for (int i = array[0]; i > 1; i--)
    {
        if (array[i] != 32)
        { 
            break;
        }
        else if (array[i] == 32)
        {
            array[0]--;
        }
    }
   
}

std::string aString::substring(int beginIndex, int length)
{
    // If no length parameter is passed in, set it to the end of the word instead
    if (length == 0)
    {
        length = array[0] - beginIndex;
    }

    // If length to check is greater than string length, cut off the exess
    if (beginIndex + length > array[0])
    {
        int overhead = (beginIndex + length) - array[0];
        length = length - overhead;
    }

    std::string build = "";
    for (int i = beginIndex + 1; i <= beginIndex + length; i++) // Increment 1 to allow for the size storage
    {
        //std::cout << char(array[i]);
        build += (char)array[i];
    }



    return build;
}

// finds one string inside another
int aString::find(char* targetString)
{
    // Work out size of target string
    int size = 0;
    while (targetString[size] != '\0')
    {
        size++;
    }
    
    //Search
    int start = 0;
    for (int i = 1; i <= array[0]; i++)
    {
        if (array[i] == targetString[0]) // first character matches
        {
            start = i - 1;
            for (int j = 1; j < size; j++)
            {
                if (array[i + j] != targetString[j]) 
                {
                    break; // Character doesnt match
                }
                else if(j == size - 1) // Whole word found
                {
                    return start;
                }
            }
        }

    }
    return -1;
}

// Finds the last occurance of a string inside another string
int aString::rfind(char* targetString)
{
    // Work out size of target string
    int size = 0;
    while (targetString[size] != '\0')
    {
        size++;
    }

    //Search
    int start = 0;
    for (int i = array[0]; i >= 1; i--)
    {
        if (array[i] == targetString[0]) // first character matches
        {
            start = i - 1;
            for (int j = 1; j < size; j++)
            {
                if (array[i + j] != targetString[j])
                {
                    break; // Character doesnt match
                }
                else if (j == size - 1) // Whole word found
                {
                    return start;
                }
            }
        }

    }
    return -1;
}

char aString::at(int index)
{
    return char(array[index + 1]);
}


// Concatenates two strings together
void aString::concatentate(char* string)
{
    // Copy old array
    int* temp;
    temp = new int[array[0] + 1]; // + 1 to include size of string at array[0]
    temp[0] = array[0];

    std::cout << "Size of array: " << temp[0] << std::endl;

    // Copy from array to temp
    for (int i = 1; i <= temp[0]; i++)
    {
        temp[i] = array[i];
    }

    delete[] array; // enables the use of the memory later
    array = nullptr; 

    // count new string
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    std::cout << "Size of new string: " << i << std::endl;
    
     // Set up new array and associated variables
    array = new int[temp[0] + i + 1]; // + 1 to include size of string at array[0]
    array[0] = temp[0] + i;

    std::cout << "Size of new array: " << temp[0] + i << std::endl;

    // Copy from temp back to array
    for (int j = 1; j <= temp[0]; j++)
    {
        array[j] = temp[j];
    }

    // Add the extra characters
    for (int j = temp[0]; j <= array[0]; j++)
    {
        if (string[j - temp[0]] == '\0')
        {
            break;
        }
        array[j + 1] = string[j - temp[0]]; // +1 to not overwrite the last written character from the previous word
    }
    
    delete[]temp; // clean up temp
    temp = nullptr;
}

void aString::concatentate(aString string)
{
    int* temp;
    temp = new int[array[0] + 1];
    temp[0] = array[0];

    for (int i = 1; i <= temp[0]; i++)
    {
        temp[i] = array[i];
    }
    delete[] array; // enables the use of the memory later

    array = new int[temp[0] + string.array[0] + 1 ]; // + 1 to allow for the storage of size at index 0
    array[0] = temp[0] + string.array[0];

    // Copy from temp back to array
    for (int j = 1; j <= temp[0]; j++)
    {
        array[j] = temp[j];
    }

    //Add the extra characters
    for (int j = temp[0] + 1; j <= array[0]; j++) // +1 to ignore string.array[0] size
    {
        array[j] = string.array[j - temp[0]]; 
    }

    delete[]temp; // clean up temp

}

void aString::push_front(char* c)
{    
    // Allocate temp array to hold all data
    int* temp;
    temp = new int[array[0] + 1];
    temp[0] = array[0];

    // Copy from array to temp
    for (int i = 1; i <= array[0]; i++)
    {
        temp[i] = array[i];
    }

    delete[] array;
    array = nullptr;

    // count new string
    int j = 0;
    while (c[j] != '\0')
    {
        j++;
    }
    array = new int[temp[0] + j + 1];
    array[0] = temp[0] + j;


    // Copy new string to array
    for (int i = 1; i <= j; i++)
    {
        array[i] = c[i - 1];
    }

    // Copy from temp back to array
    for (int i = j + 1; i <= array[0]; i++)
    {
        array[i] = temp[i - j];
    }
    
    delete[]temp;
    temp = nullptr;
    
}

char aString::pop_back()
{
    if (array[0] > 0)
    {
        char ch = (char)array[array[0]];
        array[0]--; // No need to remove the data, just shrink the size so it can no longer access it
        return ch;
    }
}


// Operator overloading

void aString::operator+=(char* s)
{
    concatentate(s);
}

void aString::operator+=(const aString &s)
{
    concatentate(s);
}

void aString::operator=(const char* s)
{
    // Get length of string
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    // Allocate memory to the string
    array = new int[i + 1];
    array[0] = i;

    // put string into array
    for (int j = 0; j < array[0]; j++)
    {
        if (s[j] == '\0')
        {
            break;
        }
        array[j + 1] = s[j];
    }

}

void aString::operator=(const std::string s)
{
    array[0] = s.length();

    for (int i = 1; i <= s.length(); i++)
    {
        array[i] = (int)s.at(i - 1);
    }
}

std::ostream& operator<<(std::ostream& os, aString& s)
{
    for (int i = 1; i <= s.array[0]; i++)
    {
        os << (char)s.array[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, aString& s)
{
    std::string in = "";
    is >> in;
    s = in;
    return is;
}


