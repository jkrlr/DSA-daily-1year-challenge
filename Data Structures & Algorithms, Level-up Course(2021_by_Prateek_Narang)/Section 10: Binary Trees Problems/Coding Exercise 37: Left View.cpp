// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Time = O(N), Space = O(LogN)-memory stack size as well as size of map are at most LogN
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
 
void leftViewTraversal(Node *root, int dist, map<int,int>&m){
   // base case
   if(root==NULL){
	return;
   }
 
   //recursive case
   if(m.count(dist)==0){
       m[dist] = root->key; // store only the first child at distance = dist
   }
   leftViewTraversal(root->left, dist + 1, m);
   leftViewTraversal(root->right, dist + 1, m);
}

vector<int> leftView(Node * root){
  map<int,int> m;
  int dist = 0;
  leftViewTraversal(root, dist, m);

  vector<int>res;
  for(auto p:m){
  	int Key = p.first;
    int nodeVal = p.second;
    res.push_back(nodeVal);
  }
  return res;
}
