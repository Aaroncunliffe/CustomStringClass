#include <iostream>
#include <string>



using namespace std;
const int maxNum = 100;	//for testing purposes keep at 5

int a[maxNum];
int b[maxNum];

// Forward Declaration
void Convert(int n, int first[]);
void Display(int first[]);
bool Subtract(int first[], int second[]);
int* Divide(int first[], int second[]);
int* Modulo(int first[], int second[]);
void Add(int first[], int second[]);
void Multiply(int first[], int second[]);
void CopyArray(int orig[], int copy[]);


void Convert(int n, int first[])
{
    string numString = to_string(n);
    int length = numString.length();

    first[0] = length;
	

    int j = first[0] - 1; // This number counts from the max length back to 0; e.g. 3 2 1 ( for int 123)
    for (int i = 1; i < first[0] + 1; i++) // For loop starting at 1 (leaves space for the length)
    {
        first[i] = numString[j] - '0'; // - 0 to force it as int, not an ascii representation
        j--;

    }
}

// Output to screen
void Display(int first[]) //TO Display THE NUMBER
{
    for (int i = first[0]; i >= 1; i--)
    {
        cout << first[i]; 
    }
    cout << endl;
}

// "first - second" returns false without altering the values if the operation would make first a negative
bool Subtract(int first[], int second[])
{ 
    bool firstLargest; // = first[0] > second[0] ? true : false;

    // Determine exactly which number is hargest
    if (first[0] > second[0])
    {
        firstLargest = true;
    }
    else if (second[0] > first[0])
    {
        return false; // Subtract error - will return negative number
    }
    else // if they both have the same number of digits
    {
        for (int i = first[0]; i >= 1; i--)
        {
            if (first[i] >= second[i]) // checks the values of the digits
            {
                firstLargest = true;
				if (first[i] == second[i] && i == 1)
				{
					first[0] = 1;
					first[1] = 0;
					return true;
				}
				break;
            }
            else
            {
                return false; // Subtract error - will return negative number
            }
        }
    }

    int max = first[0]; // Ternary operator, selects the largest size
	int difference = 0;
    for (int i = 1; i <= max; i++)
    {
		if (i > second[0])
		{
			difference = first[i];
		}
		else
		{
			difference = first[i] - second[i];
		}
			if (difference < 0) // If need to borrow
			{
				first[i + 1]--; // borrow
				difference += 10;
			}
			first[i] = difference;
		
    }

    // Trim off the left behind leading 0's
    for (int i = max; i >= 1; i--)
    {
        if (first[i] == 0)
        {
            first[0]--;
        }
        else
        {
            return true;
        }
    }
    
    return true;
}

// Returns a pointer to an array that contains the formatted number with the output of "first / second"
int* Divide(int first[], int second[])
{
    int firstCopy[maxNum];
    CopyArray(first, firstCopy);
	bool firstLargest;

	// Determine exactly which number is hargest
	if (first[0] > second[0])
	{
		firstLargest = true;
	}
	else if (second[0] > first[0])
	{
		cout << "Division Error - Will return a decimal" << endl;
		int r[maxNum];
		r[0] = 1;
		r[1] = 0;
		return r;
	}
	else // if they both have the same number of digits
	{
		for (int i = first[0]; i >= 1; i--)
		{
			if (first[i] >= second[i]) // checks the values of the digits
			{
				firstLargest = true;
			}
			else
			{
				if (first[0] != 1 && first[1] != 0)
				{
					cout << "Division Error - Will return a decimal" << endl;
				}
				int r[maxNum];
				r[0] = 1;
				r[1] = 0;
				return r;
			}
		}
	}


    if (second[1] == 0 && second[0] == 1) // second length 0
    {
        cout << "Division Error - Cannot Divide by 0" << endl;
        return first;
    }
    bool finished = false;
    int quotient = 0; // Counte for how many times you can subtract
    while (!finished)
    {
        if (!Subtract(firstCopy, second))
        {
            finished = true; // If the Subtract made the #
        }
        else
        {
            quotient++; // If Subtraction was successful
        }
    }

    int* q = new int[maxNum];
    CopyArray(first, q);
    Convert(quotient, q);
    return q;
    
}

// returns a pointer to an array that contains the formatted number with the remainder of "first / second"
int* Modulo(int first[], int second[])
{
    int* firstCopy = new int[maxNum];
    CopyArray(first, firstCopy);

	if (second[1] == 0 && second[0] == 1)
    {
        cout << "Division Error - Cannot Divide by 0" << endl;
		int r[maxNum];
		r[0] = 1;
		r[1] = 0;
        return r;
    }
    bool finished = false;
    while (!finished)
    {
        if (!Subtract(firstCopy, second))
        {
            finished = true; // If the Subtract made the 
        }
    }
    if (firstCopy[0] == 0)
    {
        Convert(0, firstCopy);
    }
    return  firstCopy;

}

// add first to second (deals with carries)
void Add(int first[], int second[])
{
    int firstCopy[maxNum]; 
    CopyArray(first, firstCopy);
    /*int secondCopy[maxNum];
    CopyArray(second, secondCopy);*/

    int carry = 0;
    // doesn't need to be EXACT, just the number of digits
    bool firstLargest = first[0] > second[0] ? true : false; // Ternary operator

    if (!firstLargest)
    {   
        // Rotate all the values to make the value in first the larger value
        int result[maxNum];
        CopyArray(second, result);
        CopyArray(first, second);
        CopyArray(result, first);
		firstLargest = true;
    }

    int limit = firstLargest ? first[0] : second[0];

    for (int i = 1; i <= limit; i++)
    {
        if (i > second[0])
        {
            first[i] = first[i] + carry; // Add together
        }
        else
        {
            first[i] = first[i] + second[i] + carry; // Add together
        }
        
        carry = 0; // Clear carry as it should've been used above if needed
        
        if (first[i]  > 9) // if need to carry
        {
            carry = 1;
            first[i] = first[i] - 10;
        }
    }
    if (carry == 1) // if carry is still 1 after the full addition, need to add 1 to the end
    {
        first[first[0] + 1] = 1;
        first[0]++;
    }
}

// Use the add function repeatedly to multiply first by second
void Multiply(int first[], int second[])
{
    bool firstLargest = first[0] > second[0] ? true : false; // Ternary operator
    if (!firstLargest)
    {
        // Rotate all the values to make the value in first the larger value
        int result[maxNum];
        CopyArray(second, result);
        CopyArray(first, second);
        CopyArray(result, first);
    }

	if (second[0] == 1 && second[1] == 0)
	{
		first[0] = 1; 
		first[1] = 0;
		return;
	}

    // Make array copies
	int secondCopy[maxNum];
	CopyArray(second, secondCopy);
    int firstCopy[maxNum];
    CopyArray(first, firstCopy);
    int origHold[maxNum];
    CopyArray(first, origHold);
    int origValue[maxNum];
    CopyArray(first, origValue);

    int count[maxNum];
    Convert(1, count);
    //Subtract(second, count); // Account for the default being times 1
    
    bool finished = false;
    while (!finished)
    {
        if (!Subtract(secondCopy, count))
        {
            finished = true; 
            return;
        }
        else
        {
            if (secondCopy[1] == 0 && secondCopy[0] == 1) // If the count reaches 0
            {
                finished = true;
                return;
            }
            Add(first, origValue); // Add over and over 
            CopyArray(origHold, origValue);
        }
    }

}

// Copy arrays
void CopyArray(int orig[], int copy[])
{
    for (int i = 0; i < orig[0] + 1; i++)
    {
        copy[i] = orig[i];
    }
}


int main()
{
    Convert(0, a);
    Convert(10, b);

    cout << "Both original numbers " << endl;
    Display(a);
    Display(b);
	

    cout<< endl;

    /*cout << "Add" << endl;
    Add(a, b);
    Display(a);
    cout << endl;*/


    /*cout << "subtract" << endl;
    if (!Subtract(a, b))
        cout << "Error - fell below 0" << endl;
    else  
        Display(a);
    cout << endl;*/

    /*cout << "Multiply" << endl;
    Multiply(a, b);
    Display(a);
    cout << endl;*/
	

    /*cout << "Divide" << endl;
    int* q = Divide(a, b);
    Display(q);
    cout << endl;*/

    /*cout << "Modulus (remainder) " << endl;
    int* r = Modulo(a, b);
    Display(r);
    cout << endl;*/
    
    system("pause");
    return 0;
}

