// Time = O(N), Space=(LogN)

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

void printAtLevelK(node *root, int k){
    // base case
    if(root==NULL){
        return;
    }
    if(k==0){
        cout << root->data << " ";
        return;
    }

    // recurive case
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int k){
    // base case
    if(root==NULL){
        return -1;
    }
    // reach the target node
    if(root==target){
        cout << root->data << " ";
        return 0;
    }

    // recursive case
    int distLeft = printNodesAtDistanceK(root->left, target, k);
    if(distLeft!=-1){
        // 2 cases 
        // print the current node
        if(distLeft+1==k){
            printAtLevelK(root,k);
        }
        // or print someNodes in right subtree
        else{
            printAtLevelK(root->right, k - 2 - distLeft);
        }
        return distLeft + 1;
    }

    int distRight = printNodesAtDistanceK(root->right, target, k);
    if(distRight!=-1){
        // 2 cases 
        // print the current node
        if(distRight+1==k){
            cout << root->data << " ";
        }
        // or print someNodes in left subtree
        else{
            printAtLevelK(root->left, k - 2 - distRight);
        }
        return distRight + 1;
    }

    return -1;
}