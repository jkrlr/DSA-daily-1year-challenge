// Time = O(N), Space = O(Height)
#include<bits/stdc++.h>
using namespace std;
 
class Node
{
  public:
   int key;
   Node *left;
   Node *right;
 
   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

// BST to Sorted Linked List
class LinkedList{
public:
    Node *head;
    Node *tail;
};

LinkedList BSTtoLinkedList(Node *root){
    LinkedList l;

    // base case
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }

    // recursive case
    /* 4 Cases */
    if(root->left==NULL && root->right==NULL){
        l.head = l.tail = root;
    }
    else if(root->left!=NULL && root->right==NULL){
        LinkedList LeftLL = BSTtoLinkedList(root->left);
        LeftLL.tail->right = root;

        l.head = LeftLL.head;
        l.tail = root;
    }
    else if (root->left==NULL && root->right!=NULL){
        LinkedList RightLL = BSTtoLinkedList(root->right);
        root->right = RightLL.head;

        l.head = root;
        l.tail = RightLL.tail;
    }
    else{
        LinkedList LeftLL = BSTtoLinkedList(root->left);
        LinkedList RightLL = BSTtoLinkedList(root->right);

        LeftLL.tail->right = root;
        root->right = RightLL.head;

        l.head = LeftLL.head;
        l.tail = RightLL.tail;
    }
    return l;
}

/* This problem is not difficult:
    The only thing you need to keep in mind is 
    How to combine the solutions from the left part and right part. 
*/

/* This is PostOrderTraveral not InorderTraversal 
   Many problems follow POST ORDER TRAVERSAL kind of logic. 
*/