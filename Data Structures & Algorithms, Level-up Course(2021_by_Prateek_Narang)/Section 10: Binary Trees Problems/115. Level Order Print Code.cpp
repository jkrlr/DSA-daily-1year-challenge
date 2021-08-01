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

/* Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
preOrderBuild => Root-Left-Right */

/* Level Order Print 
Expected Output

1
2 3
4 5 6
7
*/
void levelOrderPrint(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node *curr = q.front();
        q.pop();

        if(curr==NULL){
            cout << endl;

            // insert a new NULL for next level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << curr->data << " ";

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

