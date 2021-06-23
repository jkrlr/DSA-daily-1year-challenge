#include <iostream>
#include <cstring>
using namespace std;

void replace_space(char *str)
{
    int n = strlen(str);
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int idx = n + 2 * spaces;
    str[idx] = '\0';

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[idx - 1] = '0';
            str[idx - 2] = '2';
            str[idx - 3] = '%';
            idx -= 3;
        }
        else
        {
            str[idx - 1] = str[i];
            idx--;
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 1000);
    replace_space(input); // char array are passed by reference so, we don't need to return the output.
    cout << input << endl;
}
