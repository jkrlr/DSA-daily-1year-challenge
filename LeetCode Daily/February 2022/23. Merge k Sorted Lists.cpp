// https://leetcode.com/problems/merge-k-sorted-lists/

// Hard

// Tags - Priority Queue (min_heap), Divide and Conquer, Linked List

// What this problem wants to teach me?
// How to implement min_heap 
// How to use smaller subproblem to solve the generalize problem
// (In this case use of merge Two sorted list concept to solve the merge k sorted lists)

#include<bits/stdc++.h>
using namespace std;

// Priority Queue (min_heap) | Time = O(N*K*LogK), Space = O(K)
class ListNodeCompare{
public:
    bool operator()(ListNode* &a, ListNode* &b){
        if(a->val!=b->val)
            return a->val > b->val;
        return true;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> min_heap;
        
        for(auto& node : lists){
            if(node!=nullptr)
                min_heap.push(node);
        }
        
        ListNode* dummy = new ListNode(-1);
        
        ListNode *cur, *prev=dummy;
        while(!min_heap.empty()){
            cur = min_heap.top();
            min_heap.pop();
            
            prev->next = cur;
            prev = prev->next;
            
            if(cur->next!=nullptr)
                min_heap.push(cur->next);
        }
        
        return dummy->next;
    }
};

// Divide and Conquer -  | Time = O(N*K*LogK), Space = O(LogK) - depth of recursion
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeTwoSortedLists(lists,0,lists.size()-1);
    }
private:
    ListNode* mergeTwoSortedLists(vector<ListNode*>& lists, int start, int end){
        if(start > end)
            return nullptr;
        if(start==end)
            return lists[start];
        int mid = start + (end-start)/2;
        ListNode* head1 = mergeTwoSortedLists(lists, start, mid);
        ListNode* head2 = mergeTwoSortedLists(lists, mid+1, end);
        
        ListNode* head = merge(head1, head2);
        
        return head;
    }
    
private:
    ListNode* merge(ListNode* &head1, ListNode* &head2){
        if(head1==nullptr)
            return head2;
        if(head2==nullptr)
            return head1;
        
        ListNode *cur1 = head1, *cur2 = head2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;
        while(cur1 && cur2){
            if(cur1->val < cur2->val){
                tail->next = cur1;
                cur1= cur1->next;
            }
            else{
                tail->next = cur2;
                cur2 = cur2->next;
            }
            
            tail = tail->next;
        }
        
        if(cur1==nullptr)
            tail->next = cur2;
        else
            tail->next = cur1;
        
        return dummyNode->next;
    }
};