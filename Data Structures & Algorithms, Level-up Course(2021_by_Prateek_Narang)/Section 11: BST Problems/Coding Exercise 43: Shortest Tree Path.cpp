// Time = O(Height), Space = O(Height)

#include<bits/stdc++.h>
using namespace std;
 
class node
{
  public:
   int key;
   node *left;
   node *right;
 
   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};
 
// Time = O(Height), Space = O(Height) - for BST
node* lca(node*root, int a, int b){
   // base case
   if(root==NULL){
       return NULL;
   }
 
   // recursive case
   /* 1. ancestor lies in left subtree */
   if (a < root->key && b < root->key){
       return lca(root->left, a, b);
   }
   /* 2. ancestor lies in right subtree */
   else if (a > root->key && b > root->key){
       return lca(root->right, a, b);
   }
   /* 3. current node is ancestor
   i.e. if((a < root->data && root->data < b) || root->data==a || root->data==b)*/
   else{
       return root;
   }
}
 
int distFromLCA(node *Lca, int data){
	// base case
    if(Lca->key == data){
		return 0;
	}
	
	// recursive case
	if(data < Lca->key){
		return 1 + distFromLCA(Lca->left,data);
	}
	else{
		return 1 + distFromLCA(Lca->right,data);
	}
}
 
//here nodes a and b are the inputs
int shortestDist(node * root,int a,int b){
    //first find LCA 
	node *Lca = lca(root,a,b);
	if(Lca==NULL){
		return -1;
	}
 
	// Then calculate the distance of each node from LCA
	int distA = distFromLCA(Lca,a);
	int distB = distFromLCA(Lca,b);
 
    return distA + distB;   
}
 
 
