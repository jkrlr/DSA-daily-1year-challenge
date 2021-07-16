#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
    // Base Case

    if (input[i] == '\0')
    {
        // We're using string object which is null terminating already, So we don't required to put null character in it.
        // If we're using character array , then we need to add null character in the output before printing it.
        cout << output << ", ";
        return;
    }

    // Recursive Case

    int curr_digit = input[i] - '0';

    // In the interview you can clarify with the interviewer,
    // Such case exist or not?
    if (curr_digit == 0 or curr_digit == 1)
    { // Then simply move to the next digit
        printKeypadOutput(input, output, i + 1);
    }

    // We can't hardcode this for loop because In some cases it runs 3 times while in some cases it runs 4 times.
    for (int k = 0; k < keypad[curr_digit].size(); k++)
    {
        printKeypadOutput(input, output + keypad[curr_digit][k], i + 1);
    }
    // return;
}

int main()
{
    string input, output;
    cin >> input;

    printKeypadOutput(input, output);
}