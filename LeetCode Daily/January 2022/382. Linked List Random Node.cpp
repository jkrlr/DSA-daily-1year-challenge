// https://leetcode.com/problems/linked-list-random-node/

// Medium

// Tags - Randomized - rand(), Reserviour sampling

// What this problems wants to teach me?
// How to generate random numbers having equal probability in C++ by using rand() of range 0 to RAND_MAX (or 0 to less than 1)
// How to pick elements of equal probability by using simple sampling and reserviour sampling
// Study the proof of reserviour sampling

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Fixed-Range Sampling | Random generator - rand() | Time = O(N), Space = O(N)
/* Intuition
    First of all, let us talk about the elephant in the room. 
    Yes, the problem could be as simple as choosing a random sample from a list, 
    which in our case happens to be a linked list. */
class Solution {
private:
    vector<int> range;
public:
    Solution(ListNode* head) {
        while(head!=NULL){
            range.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int pick = (int)(((double) rand() / (RAND_MAX)) * range.size());
        return range[pick];
    }
};

// Approach 2: Reservoir Sampling | Time = O(N), Space = O(1)
/* Intuition
    In order to do random sampling over a population of unknown size with constant space, the answer is reservoir sampling. 
    As one will see later, it is an elegant algorithm that can address the two caveats of the previous approach. */
/* The reservoir sampling algorithm is intended to sample k elements from an population of unknown size. 
    In our case, the k happens to be one. */
class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int scope = 1, choosenValue = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            // decide whether to include the element in reservoir
            if(((float)rand()/RAND_MAX) < 1.0/scope)
                choosenValue = curr->val;
                
            // move on to the next node
            scope += 1;
            curr = curr->next;
        }
        
        return choosenValue;
    }
};
