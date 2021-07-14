#include <iostream>
using namespace std;

void GenerateBrackets(string output, int n, int opening, int closing, int idx)
{
    // Base Case
    if (idx == 2 * n)
    {
        cout << output << endl;
        return;
    }

    // Recursive Case

    // opening
    if (opening < n)
    {
        GenerateBrackets(output + '(', n, opening + 1, closing, idx + 1);
    }

    // closing
    if (closing < opening)
    {
        GenerateBrackets(output + ')', n, opening, closing + 1, idx + 1);
    }
}

int main()
{
    string output;
    int n;
    cin >> n;
    GenerateBrackets(output, n, 0, 0, 0);
}