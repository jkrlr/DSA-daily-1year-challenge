// PostOrderTraversal Example - Building the solution in bottom-up manner

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

// Diameter Optimized - Time = O(N), Space = O(LogN)
class HDPair{
public:
    int diameter;
    int height;
};

HDPair optimizedDiameter(node *root){
    HDPair p;

    // base case
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }

    // recursive case
    HDPair Left = optimizedDiameter(root->left);
    HDPair Right = optimizedDiameter(root->right);

    p.height = max(Left.height, Right.height) + 1;  // Calculate height of current node

    // Calculate diameter of current node
    int d1 = Left.height + Right.height;
    int d2 = Left.diameter;
    int d3 = Right.diameter;

    p.diameter = max(d1, max(d2, d3));

    return p;
}