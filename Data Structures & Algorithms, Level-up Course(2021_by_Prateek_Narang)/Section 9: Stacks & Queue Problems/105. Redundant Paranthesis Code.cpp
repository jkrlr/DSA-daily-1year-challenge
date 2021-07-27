// Easy - Time = O(n), Space = O(n)-for stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkRedundant(string str)
{
    stack<char> s;

    for (char ch : str)
    {
        // If ch is not closing bracket - push
        if (ch != ')') // ch == a,b,+,-,'('...
        {
            s.push(ch);
        }
        else
        { // ch == ')'
            bool operator_found = false;
            while (!s.empty() && s.top() != '(')
            {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    operator_found = true;
                }
                s.pop();
            }

            s.pop(); // pop the opening bracket after the loop is over

            if (operator_found == false)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    string str = "((a+b)+c)";

    if (checkRedundant(str))
    {
        cout << "Contains Redundant Paranthesis!" << endl;
    }
    else
    {
        cout << "Doesn't contains Redundant Paranthesis!" << endl;
    }
}