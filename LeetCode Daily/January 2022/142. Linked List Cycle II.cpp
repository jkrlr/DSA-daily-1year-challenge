// https://leetcode.com/problems/linked-list-cycle-ii/

// Medium

// Tags - fast and slow pointer technique, move one of the pointer by some k node ahead from the head
//      - HashTable(Unordered_Set), Two-Pointer, LinkedList


// What this problem wants to teach me?
// For two pointer meet in a cycle is that the ratio of speed of fast to slow should be greater than 1
// which means (fast/slow) > 1 , but the most optimal answer is comes for (fast/slow) = 2
// Detailed explanation of fast and slow pointer technique


#include<bits/stdc++.h>
using namespace std;

// Solution valid for only (fast/slow) = 2 | Time - O(2N = (A + (C+(B+C))), Space - O(1)
// fast and slow pointer technique
class Solution {
public:
    ListNode* detectCycle(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode* meet = head;
                while(slow!=meet){
                    slow = slow->next;
                    meet = meet->next;
                }
                
                return meet;
            }
        }

        return NULL;	
    }
};

// fast and slow pointer technique + move one of the pointer by some k node ahead from the head | Time = O(4*N), Space = O(1)
class Solution {
public:
    ListNode* detectCycle(ListNode* head){
        // Check if cycle is present or not
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }
        // No cycle in Linked List
        if(fast == NULL || fast->next == NULL)
            return NULL;

        // calculate the cylcle length;
        slow = slow->next;
        int cycleLen = 1;
        while(slow!=fast){
            cycleLen++;
            slow = slow->next;
        }

        // move the forward pointer by cycleLen Nodes ahead from the head
        ListNode* forward = head;
        for(int i=0; i<cycleLen; i++)
            forward = forward->next;
        
        // when both forward and backward meet, they meet at beginning node of cycle
        ListNode* backward = head;
        while(forward!=backward){
            forward = forward->next;
            backward = backward->next;
        }

        return backward;	
    }

};