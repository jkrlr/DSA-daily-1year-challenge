#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

string extractStringAtKey(string str, int key)
{
    // string tokeniser
    // hello how are you

    // strtok() => takes char array as input and delimeter
    char *s = strtok((char *)str.c_str(), " "); // c_str() => converts string to underlying Cstring.
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }

    return string(s);
}

int convertToInt(string s)
{
    int ans = 0;
    int power = 1;

    // "321" => 0 + 1 -> 1 + 2*10 -> 21 + 3*100 = 321
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans += (s[i] - '0') * power; // s[i] - '0' => gives the integer digit
        power *= 10;
    }
    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return key1 < key2; // '<' operator is already defined for string class object
}

int main()
{

    int n;
    cin >> n;

    cin.get(); // consumes extra '\n'

    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp); // includes white spaces
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // 1. To extract keys for comparison & store them
    vector<pair<string, string>> vp; // pair<string,keyString>
    for (int i = 0; i < n; i++)
    {
        vp.push_back({v[i], extractStringAtKey(v[i], key)});
    }

    // 2. Sort
    if (ordering == "numeric")
    {
        sort(vp.begin(), vp.end(), numericCompare);
    }
    else
    {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }

    // 3. Reversal
    if (reversal == "true")
    {
        reverse(vp.begin(), vp.end());
    }

    // 4. Output
    for (int i = 0; i < n; i++)
        cout << vp[i].first << endl;
}

// Very Imp. Question to Revise

/* The Learning is you need to break down your code into small funtions.
This will help to simplify things and
If you stuck at some point => do check the implementaion of every small funtions seperately */