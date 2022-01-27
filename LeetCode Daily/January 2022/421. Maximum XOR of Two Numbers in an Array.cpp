// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Medium

// Tags - Trie, Bit Manipulation

// What this problem wants to teach me?
// How to use Trie with Bitmasking

#include<bits/stdc++.h>
using namespace std;

// Trie, Bit Manipulation | Time - O(32*N), Space - O(32*N)
class Node{
public:
    Node* unsetbit;
    Node* setbit;
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int value){
        Node* currNode = root;
        
        for(int i=31; i>=0; i--){
            int bit = (value>>i) & 1;
            
            if(bit==0){
                if(currNode->unsetbit==NULL){
                    currNode->unsetbit = new Node();
                }
                currNode = currNode->unsetbit;
            }
            else{
                if(currNode->setbit==NULL){
                    currNode->setbit = new Node();
                }
                currNode = currNode->setbit;
            }
        }
    }
    
    int maxXorHelper(int value){
        Node* currNode = root;
        int mxXor = 0;
        for(int i=31; i>=0; i--){
            int bit = (value>>i) & 1;
            
            if(bit==0){
                if(currNode->setbit!=NULL){
                    mxXor += (1<<i);
                    currNode = currNode->setbit;
                }
                else
                    currNode = currNode->unsetbit;
            }
            else{
                if(currNode->unsetbit!=NULL){
                    mxXor += (1<<i);
                    currNode = currNode->unsetbit;
                }
                else
                    currNode = currNode->setbit;
            }
        }
        
        return mxXor;
    }
    
    int maxXor(vector<int>& nums){
        int mxXor = 0, currXor = 0;
        for(int& value: nums){
            insert(value);
            currXor = maxXorHelper(value);
            mxXor = max(mxXor, currXor);
        }
        return mxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        return t.maxXor(nums);
    }
};