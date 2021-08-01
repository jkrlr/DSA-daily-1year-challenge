// PostOrderTraversal Example - Building the solution in bottom-up manner
// Time = O(N)-since we're going to each node once only, Space = O(LogN)

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


class InExPair{
public:
    int include;
    int exclude;
};

// Max Subset Sum
InExPair maxSubsetSum(node *root){
    InExPair p;

    // base case
    if(root==NULL){
        p.include = p.exclude = 0;
        return p;
    }

    // recurisve case
    /* First build left and right subtree, Then apply recurrence */
    InExPair Left = maxSubsetSum(root->left);
    InExPair Right = maxSubsetSum(root->right);

    p.include = root->data + Left.exclude + Right.exclude;
    p.exclude = max(Left.include, Left.exclude) + max(Right.include, Right.exclude);

    return p;
}
