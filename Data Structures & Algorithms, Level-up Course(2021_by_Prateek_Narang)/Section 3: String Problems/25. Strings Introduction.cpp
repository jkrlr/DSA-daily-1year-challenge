#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // char s[1000] = {'1', 'a', 'b', 'c', '\0'};
    // string s = "hello world"; // Dynamic Array
    // string s("hello world"); // By calling the constructor

    string s;

    getline(cin, s, '.'); // The argument is delimeter i.e. when to stop taken input

    for (char ch : s)
    {
        cout << ch << ",";
    }
    cout << s << endl;

    //vector<string> .....

    // We can also take multiple strings as input
    int n = 5;
    vector<string> sArr;

    string temp;

    while (n--)
    {
        getline(cin, temp);
        sArr.push_back(temp);
    }

    for (string x : sArr)
    {
        cout << x << "," << endl;
    }
}