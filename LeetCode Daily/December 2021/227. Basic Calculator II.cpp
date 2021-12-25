// https://leetcode.com/problems/basic-calculator-ii/ 

// Medium

// Tags - Math-Operator precedence, Array, Stack

// https://leetcode.com/problems/basic-calculator-ii/Figures/227/calculator_overview.png

#include<bits/stdc++.h>
using namespace std;

// Math-Operator precedence, Stack | Time = O(N), Space = O(N/2)==O(n)-for stack
// Here N==string.length(), n = cnt of operators in string

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char prevOperator = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (prevOperator == '-') {
                    stack.push(-currentNumber);
                } else if (prevOperator == '+') {
                    stack.push(currentNumber);
                } else if (prevOperator == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (prevOperator == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                prevOperator = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};

// Math-Operator precedence | Time = O(N), Space = O(1)
class Solution {
public:
    int calculate(string s) {
        
        if(s.length()==0)
            return 0;
        
        int currentNumber = 0;
        char prevOperator = '+';
        int result=0;
        int lastNumber = 0;
        
        for(int i=0; i<s.length(); i++){
            char currentChar = s[i];
            
            if(isdigit(currentChar)){
                currentNumber = (currentNumber*10) + (currentChar - '0');
            }
            if(!isdigit(currentChar) && !iswspace(currentChar) || i==s.length()-1){
                if(prevOperator == '-'){
                    result += lastNumber;
                    lastNumber = -currentNumber;
                }
                else if(prevOperator == '+'){
                    result += lastNumber;
                    lastNumber = currentNumber;
                }
                else if(prevOperator == '*'){
                    lastNumber = lastNumber * currentNumber;
                }
                else if(prevOperator == '/'){
                    lastNumber = lastNumber / currentNumber;
                }
                
                prevOperator = currentChar;
                currentNumber = 0;
            }
        }
        
        result += lastNumber;
        return result;
    }
};