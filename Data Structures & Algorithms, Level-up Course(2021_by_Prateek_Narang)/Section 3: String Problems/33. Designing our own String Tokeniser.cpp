#include <iostream>
#include <cstring>
using namespace std;

char *mystrtok(char *str, char delim)
{
    // static
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }
    if (input == NULL)
        return NULL;

    // Why dynamic arrays? We can return dynamic arrays not static arrays.
    char *token = new char[strlen(input) + 1]; // +1 for the null character
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            token[i] = input[i];
        }
        else
        {
            token[i] = '\0';
            input = input + i + 1;

            // When multiple delim are consecuative in input, skip all those
            // e.g. (Hello  World   !   !), should return (Hello, World, !, !) 
            while(input[0]==delim){
            	input +=1;
            }
            return token;
        }
    }

    // out of the loop
    token[i] = '\0';

    // reset the input as NULL
    input = NULL;

    return token;
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);

    char *token = mystrtok(input, ' ');

    while (token != NULL)
    {
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }
}
/* Why dynamic array? 
Because we want to return the array 
If we create an static array. Then it will be local variable 
and it will get destroyed when the function call ends.
*/
