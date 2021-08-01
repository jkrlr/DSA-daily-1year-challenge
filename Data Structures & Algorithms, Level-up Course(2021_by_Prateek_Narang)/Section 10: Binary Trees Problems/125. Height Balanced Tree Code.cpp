// PostOrderTraversal Example - Left-Right-Root
// Time = O(N), Space = O(LogN)

#include<iostream>
using namespace std;

class node{

public:
    int data;
    node *left;
    node *right;
    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Height Balanced Tree
pair<int,bool> isHeightBalanced(node *root){
    // pair<height,balanced>
    pair<int, bool> p;

    // base case
    if(root==NULL){
        p.first = 0;      // height
        p.second = true; // balanced
        return p;
    }

    // recursive case(PostOrderTrversal)
    // First build the left and right subtree
    pair<int, bool> Left = isHeightBalanced(root->left);
    pair<int, bool> Right = isHeightBalanced(root->right);

    int height = max(Left.first, Right.first) + 1;

    // Left.balanced && Right.balanced && abs(HL-HR)<=1
    if(Left.second && Right.second && abs(Left.first - Right.first)<=1){
        return make_pair(height, true);
    }
    return make_pair(height, false);
}