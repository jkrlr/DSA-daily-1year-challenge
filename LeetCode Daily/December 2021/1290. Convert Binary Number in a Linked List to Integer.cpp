// https://leetcode.com/problems/house-robber-iii/

// Medium

// Tags - BinaryToDecimal Conversion, Bit Manipulation, Maths-Addition/Multiplication

// What this problem wants to teach me?
// How to convert Binary Number to a Decimal Number(traversing Left->Right) using Simple Math and using Bit-Manipulation
// Bit Manipulation is slightly faster than Normal Math
// We can convert product into sum by expanding the sequence of int and sum into product by contracting the series of int
// and then look for common part (factor), It'll be helpful in expansion/contraction
// If we have path only forward direction not in backward direction like Binary Tree Pointers or Singly LinkedList Pointers
// And we want to calculate the answers from Bottom to Top or Right to Left direction(or simly in reverse direction)
// Then we can use Recursion for single pass with O(n) memory cost to compute the answer from backward side(In PostOrder Manner)
// Accordingly chnage the required varaibles as they required for prvious while Backtracking

#include <bits/stdc++.h>
using namespace std;

// Binary Representation | Time = O(n), Space = O(1)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        if(head==NULL)
            throw invalid_argument("List is empty!");
        
        int res = head->val;
        head = head->next;
        
        while(head){
            res = (res*2) + head->val;  // Main Logic
            head = head->next;
        }
        
        return res;
    }
};

// Bit Manipulation | Time = O(n), Space = O(1)
// This approach is slightly faster than Binary Representaion apporach
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        if(head==NULL)
            throw invalid_argument("List is empty!");
        
        int res = head->val;
        head = head->next;
        
        while(head){
            res = (res<<1) | head->val; // Main Logic
            head = head->next;
        }
        
        return res;
    }
};

// Recursive | Time = O(n), Space = O(n)-recursive traversal
class Solution {
public:
    int power = 0;
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        
        // PostOrder Type 
        return getDecimalValue(head->next) + (head->val)*(1<<power++);
    }
};

// Naive Solution/Brute-Force
// String + BinaryToDecimal Conversion | Time = O(n), Space = O(n)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        string binary;
        while(head){
            binary += (char)(head->val + '0');
            head = head->next;
        }
        
        int n = binary.length();
        int res = 0;
        for(int i=n-1; i>=0; i--){
            int power = (n-i-1);
            int digit = binary[i] - '0';
            
            res += (1<<power)*digit;
        }
        
        return res;
    }
};