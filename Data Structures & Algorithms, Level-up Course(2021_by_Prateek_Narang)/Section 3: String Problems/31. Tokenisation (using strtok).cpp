#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    char input[1000];
    cin.getline(input, 1000);

    //strtok()
    /*cout << strtok(input, " ") << endl;

    cout << strtok(NULL, " ") << endl; // Internally maintains the state of string you passed in the last function call,by making a static variable
    cout << strtok(NULL, " ") << endl;
    cout << strtok(NULL, " ") << endl;  */

    char *token = strtok(input, " ");

    while (token != NULL) // strtok() returns NULL once all the tokens has been done
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}
