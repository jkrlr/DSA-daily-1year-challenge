#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
}

int main()
{
    string input, output;
    cin >> input;

    printKeypadOutput(input, output);
}