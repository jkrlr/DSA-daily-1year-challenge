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
 
int findClosestInBST(Node *root, int target){
    int closest = -1;
    int diff = INT_MAX;
    Node *temp = root;

    while(temp!=NULL){
        int currDiff = abs(target - temp->key);

        if(currDiff==0){
            return temp->key;
        }
        if(currDiff < diff){
            closest = temp->key;
            diff = currDiff;
        }
 
		if(target < temp->key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
	
	return closest;
}
 
