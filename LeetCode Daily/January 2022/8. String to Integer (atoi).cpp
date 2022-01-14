// https://leetcode.com/problems/string-to-integer-atoi/

// Medium

// Tags - String Traversal, isdigit(), integer overflow concept

// What this problem wants to teach me?
/* isdigit() function takes the character as a argument to check whether it is decimal digit from 0 to 9 or not
    If you give direct int argument not the char then it will return false */
/* If you don't know the exact argument type and return type...then use fundamental conditions for condition checking
    or simply run the code for different types of inputs and by using print statement you can draw the conclusion */
/* While adding/substracting/multiplying two numbers and the result may go out of bound to the integer limits
    then, while storing the result into long int type don't forget to typecast all the numbers of expression into long
    otherwise it will give overflow */
/* In LeetCode OJ, while thinking the edge case and want the confirmation for answer like interviewer.
    then, return the 0 or empty or null result and enter the edge case/test case into the console and
    run the code...then the expected answer given by OJ is the right answer...then write code accordingly */

// String Traversal, isdigit(), integer overflow concept | Time - O(N), Space - O(1)
class Solution {
public:
    int myAtoi(string s) {        
        int i=0;
        
        // remove beginning leading whitespaces 
        while(i<s.length() && s[i]==' ')
            i++;
        
        // check if next char is '+' or '-'
        char symbol = '+';
        if(i<s.length() && (s[i]=='-' || s[i]=='+'))
            symbol = s[i++];
        
        // check if next char is digit char or not
        // If not return 0;
        if(i<s.length() && (s[i]>='0' && s[i]<='9')==false){
            return 0;
        }
        // Skip all the leading zeros
        /* while(i<s.length() && s[i]=='0') 
            i++; */
        
        // calculate the clamped positive result
        long result = 0;
        long maxLimit = (long)INT_MAX + 1;
        while(i<s.length() && isdigit(s[i])){
            result = result*10 + s[i] - '0';
            i++;
            
            if(result >= maxLimit)
                break;
        }
        
        // Return the clamped result with symbol
        if(symbol == '-'){
            if(result >= maxLimit)
                return INT_MIN;
            else
                return (int)(-1*result);
        }
        else{
            if(result >= maxLimit-1)
                return INT_MAX;
            else
                return (int)result;
        }     
    }
};