// https://leetcode.com/problems/add-binary/

// Easy

// Tags - String, Math - Binary Addition

// What this problem wants to teach me?
// In while loop condition is true for both +ve and -ve integers and only false for 0.
// How to write shorter code for merge sort merge like simultaneous traversal

// Simultaneous Linear Traversal | Time - O(2*max(m,n)), Space - O(1) , here m==a.length and n==b.length
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        
        int idxA = a.length()-1, idxB = b.length()-1;
        
        while(idxA>=0 || idxB>=0 || carry==1){
            int digitA = idxA>=0 ? a[idxA] - '0' : 0;
            int digitB = idxB>=0 ? b[idxB] - '0' : 0;
            
            int total = digitA + digitB + carry;
            char ch = (total % 2) + '0';    // taking mod by 2 bcoz binary no.s given in question
            result.push_back(ch);
            carry = total/2;
            
            idxA--;
            idxB--;
        }
        
        if(carry==1)
            result.push_back('1');
        
        reverse(result.begin(), result.end());
        return result;
    }
};

// Linear Traversal | Time - O(2*max(m,n)), Space - O(1) , here m==a.length and n==b.length

class Solution {
public:
    string addBinary(string a, string b) {
       int idxA = a.length()-1,  idxB = b.length()-1;
        char carry = '0';
        string result;
        while(idxA>=0 && idxB>=0){
            if(a[idxA]=='1' && b[idxB]=='1'){
                if(carry=='1')
                    result.push_back('1');
                else
                    result.push_back('0'), carry = '1';
            }
            else if(a[idxA]=='0' && b[idxB]=='0'){
                if(carry =='1')
                    result.push_back('1'), carry = '0';
                else
                    result.push_back('0');
            }
            else{
                if(carry == '1')
                    result.push_back('0');
                else
                    result.push_back('1');
            }
            idxA--, idxB--;
        }
    
        while(idxA>=0){
            if(a[idxA]=='1'){
                if(carry=='1')
                    result.push_back('0');
                else
                    result.push_back('1');
            }
            else{
                if(carry =='1')
                    result.push_back('1'), carry = '0';
                else
                    result.push_back('0');
            }
            
            idxA--;
        }

        while(idxB>=0){
            if(b[idxB]=='1'){
                if(carry=='1')
                    result.push_back('0');
                else
                    result.push_back('1');
            }
            else{
                if(carry =='1')
                    result.push_back('1'), carry = '0';
                else
                    result.push_back('0');
            }
            
            idxB--;
        }
        
        if(carry=='1')
            result.push_back('1');
        
        reverse(begin(result), end(result));
        
        return result;
    }
};