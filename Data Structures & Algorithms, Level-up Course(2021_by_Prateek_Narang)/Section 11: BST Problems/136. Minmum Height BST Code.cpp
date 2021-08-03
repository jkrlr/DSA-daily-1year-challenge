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
 
Node * sortedArrayToBST(vector<int> arr, int start, int end){
	// base case
	if(start > end){
        return NULL; // because no array elements are there
    }

    // recursive case
    // get the middle element and make it root
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);

    // create left and right subtree recurively
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
 
