// https://leetcode.com/problems/number-complement/

// Easy

// Tags - Bit Manipulation

// What this problem wants to teach me?
// '+' operator has higher precedence than '<<' operator
// So, use parantheses for evaluation the left shif operator with '+'

#include<bits/stdc++.h>
using namespace std;

// Bit Manipulation | Time = O(n), Space = O(1) , n= no. of bits in number
class Solution {
public:
    int findComplement(int num) {
        int i=0;
        int result = 0;
        while(num){
            if((num&1)==0)
                result += (1<<i);
            
            i+=1;
            num = (num>>1);
        }
        
        return result;
    }
};

// Brute-Force | Time = O(3*n), Space = O(n) , n= no. of bits in number
class Solution {
string convertToBinary(int num){
    string result;
    while(num){
        result.push_back(num%2 + '0');
        num/=2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}
    
void convertToComplement(string& binary){
    for(char& ch: binary){
        if(ch=='1')
            ch = '0';
        else
            ch = '1';
    }
}
    
int convertToDecimal(string& binary){
    int ans = 0;
    int power = 0;
    for(int i=binary.length()-1; i>=0; i--){
        int bit = binary[i] - '0';
        ans += (1<<power)*bit;
        power++;
    }
    
    return ans;
}
public:
    int findComplement(int num) {
        string binary = convertToBinary(num);
        convertToComplement(binary);
        return convertToDecimal(binary);
    }
};