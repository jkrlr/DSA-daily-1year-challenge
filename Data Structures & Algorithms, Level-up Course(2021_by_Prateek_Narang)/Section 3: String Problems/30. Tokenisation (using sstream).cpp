#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    string input;
    getline(cin, input); // Whenever you declare a string using 'string' => Always take input throug getline function

    // create a string stream object
    stringstream ss(input); // this creates a like a buffer string => In which we can read data and write data

    // supports "<<" and ">>" operations
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    // print all the tokens
    for (auto token : tokens)
        cout << token << ",";
}
