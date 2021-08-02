// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Time = O(NLogN)-for sorting, Space=(N)

#include<bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

vector<int> res;

void storeAtLevelK(node *root, int k){
    // base case
    if(root==NULL){
        return;
    }
    if(k==0){
        res.push_back(root->data);
        return;
    }

    // recurive case
    storeAtLevelK(root->left, k - 1);
    storeAtLevelK(root->right, k - 1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int k){
    // base case
    if(root==NULL){
        return -1;
    }
    // reach the target node
    if(root==target){
        storeAtLevelK(root,k);
        return 0;
    }

    // recursive case
    int distLeft = printNodesAtDistanceK(root->left, target, k);
    if(distLeft!=-1){
        // 2 cases 
        // print the current node
        if(distLeft+1==k){
            res.push_back(root->data);
        }
        // or print someNodes in right subtree
        else{
            storeAtLevelK(root->right, k - 2 - distLeft);
        }
        return distLeft + 1;
    }

    int distRight = printNodesAtDistanceK(root->right, target, k);
    if(distRight!=-1){
        // 2 cases 
        // print the current node
        if(distRight+1==k){
            res.push_back(root->data);
        }
        // or print someNodes in left subtree
        else{
            storeAtLevelK(root->left, k - 2 - distRight);
        }
        return distRight + 1;
    }

    return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k){
    res.clear();    // for multiple test cases

    printNodesAtDistanceK(root, target, k);
    sort(res.begin(),res.end());    // NLogN

    return res;
}