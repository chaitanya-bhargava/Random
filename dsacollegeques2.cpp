#include <iostream>
#include <stdlib.h>
using namespace std;

bool isPalindrome(int i, int j, string original)
{
    // Swap the two characters
    char temp = original[i];
    original[i] = original[j];
    original[j] = temp;

    int len = size(original);
    for (int i = 0; i < len; i++)
    {
        // Compare first and last element,second and second-last....
        if (original[i] != original[len - i - 1])
        {
            return false; // Function will become false even if characters are not equal once
        }
    }
    
    // This will only run when if statement will always be false or the new array is a palindrome
    return true;
}

int main()
{
    int t;
    cout << "Enter number of testcases:\n";
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        string original;
        cout << "Enter string:\n";
        cin >> original;
        int len = size(original);
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 1; j < len; j++)
            {
                // Check every possible pair of swaps and if that makes a palindrome
                if (isPalindrome(i, j, original))
                {
                    goto palindromecheck;
                    // If for any swap isPalindrome becomes true we jump to the print statement(It is a palindrome)
                }
            }
        }
        
        // If for no swap isPalindrome is true then we reach here
        cout << "It is not a palindrome\n";
        continue; // continue is placed so that It is a palindrome doesn't also get printed
    
        palindromecheck:
        cout << "It is a palindrome\n";
    }
    return 0;
}