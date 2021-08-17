// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Time = O((26 + 26)*N), Space = (26*N)

// xor will be type of int and doesn't cause overflow - if all the nums are positive integers 
// because in that case the possible max value is when all the 32 bits are set because we're taking xor
// casues only overflow if somehow we are adding number i.e. the case of or operation
// althought bitwise or/and/xor => | / & / ^ operations on two numbers doesn't cause overflow

// If we maintain the arr as it is - then this trie max_xor function returns the max value of xor
// of each number that can be possible with previous numbers in O(1) time at each step.

// This solution is based upon that - we have to consider leftmost bit(MSB) first to get more weightage in answer

/* 
        // Another solution - first find max 
        //- then xor with each element and find max xor 

        fails for below test case 
        Input
                 [8,10,2]
        Output
                    8
        Expected
                    10
 */

// Think yourself the other corner case as well - when some solution sticks into your mind

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *left;
    node *right;
};

class trie{
    node *root;

public:
    trie(){
        root = new node();
    }

    void insert(int num){

        node *temp = root;

        // Extract the bits and insert it into trie
        for(int i = 31; i >= 0;i--){
            int bit = (num >> i) & 1;

            if(bit==0){
                if(temp->left==NULL){
                    temp->left = new node();
                }
                // go to that node
                temp = temp->left;
            }
            else{ // bit == 1
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int num){
        node *temp = root;
        int curr_xor = 0;
        
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(bit==0){
                // look for one
                if(temp->right!=NULL){
                    curr_xor += (1 << i);
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            else{ // bit == 1
                // look for zero
                if(temp->left!=NULL){
                    curr_xor += (1 << i);
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        return curr_xor;
    }

    int max_xor(vector<int> input){

        int max_xor = 0;
        for (int num : input){
            insert(num);
            int curr_xor = max_xor_helper(num);
            max_xor = max(max_xor, curr_xor);
        }

        return max_xor;
    }
};

int max_xor_pair(vector<int> arr){    

    trie t;
    return t.max_xor(arr);
}