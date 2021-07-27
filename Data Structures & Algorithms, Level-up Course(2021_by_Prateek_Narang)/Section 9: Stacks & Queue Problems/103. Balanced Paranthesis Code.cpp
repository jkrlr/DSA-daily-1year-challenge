// Easy - Time = O(n), Space = O(n)-for stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string input)
{
    stack<char> s;

    for (char ch : input)
    {

        // If ch is opening bracket - push into stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // If ch is opening bracket - match with top and perform pop or return false
        else if (ch == ')')
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == '}')
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (ch == ']')
        {
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // check stack is empty or not
    // stack is not empty is cnt of opening!=closing
    if (s.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    string input = "((a+b+c)+[d])";

    if (isBalanced(input))
    {
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced!" << endl;
    }
}