#include<iostream>
#include<queue>

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

/* Input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 
/* Level Order Print 
Expected Output
1
2 3 
4 5 6
7
*/

// levelOrderBuild
node *levelOrderBuild(){

    // 1. Build the root
    int d;
    cin >> d;

    node *root = new node(d);

    queue<node*> q;
    q.push(root);

    // 2. Build remaining subtree
    while(!q.empty()){
        node *curr = q.front();
        q.pop();

        // Input Left and Right child
        int child1, child2;
        cin >> child1 >> child2;

        // Left child
        if(child1!=-1){
            node *left = new node(child1);
            curr->left = left;
            q.push(left);
        }

        // Right child
        if(child2!=-1){
            node *right = new node(child2);
            curr->right = right;
            q.push(right);
        }
    }
    return root;
}
