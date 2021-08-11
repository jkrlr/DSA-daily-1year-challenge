// Time = O(N), Space = O(N)
#include<bits/stdc++.h>
using namespace std;
 
class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};
 
// hash via address
// if node-> next in hash , then simply node * next = NULL
// return head

node *breakChain(node *head){

    unordered_set<node *> s; // Hint : You may use address as key for hashing because the list contains duplicates as well
    node *temp = head;

    // Traverse until last node
    while (s.count(temp->next) != 1){
        s.insert(temp);
        temp = temp->next;
    }

    temp->next = NULL;  // break the cycle 
    return head;
}
