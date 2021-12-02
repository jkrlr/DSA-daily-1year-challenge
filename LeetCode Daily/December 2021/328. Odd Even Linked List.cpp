https://leetcode.com/problems/odd-even-linked-list/

// Medium

// Tags - LinkedList, Pointer-Manipulation

// What this problem wants to teach me?
// We can use two pointers(or few more than 2) to manipulate the ordering the Linked List nodes
// We can declare multiple pointers by using the type once and adding * to every variable name in sinlge line
// And for each declared pointer you have to assing values individually like ptrA = somePtr, ptrB = somePtr not like that ptrA=ptrB= somePtr

#include<bits/stdc++.h>
using namespace std;

// Pointer-Manipulation | Time = O(n), Space = O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        
        ListNode *odd = head, *oddHead = head;   // Pay attention on pointers declaration here 
        ListNode *even = head->next, *evenHead = head->next;
        
        while(even!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        
        return oddHead;
    }
};