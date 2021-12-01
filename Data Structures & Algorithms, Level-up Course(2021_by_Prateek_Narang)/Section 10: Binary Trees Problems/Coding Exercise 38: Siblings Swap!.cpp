// https://leetcode.com/problems/flip-equivalent-binary-trees/
// Time = O(N), Space = O(H)
// Coding Exercise 38: Siblings Swap!
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};

bool equal(Node *root1, Node *root2){
    // LevelOrderTraversal question
    queue<Node *> q1, q2;

    q1.push(root1);
    q1.push(NULL);
    q2.push(root2);
    q2.push(NULL);

    vector<int> sameLevel1;
    vector<int> sameLevel2;

    while (!q1.empty() && !q2.empty()){
        Node *curr1 = q1.front();
        Node *curr2 = q2.front();
        q1.pop();
        q2.pop();

        if (curr1 == NULL && curr2 == NULL){ // O(LogN.LogN*Log(LogN))
            // Compare both Tree elements of same level
            sort(sameLevel1.begin(), sameLevel1.end()); // O(LogN*Log(LogN))
            sort(sameLevel2.begin(), sameLevel2.end());

            for (int i = 0; i < sameLevel1.size(); i++){
                if (sameLevel1[i] != sameLevel2[i]){
                    return false;
                }
            }
            if(!q1.empty() && !q2.empty()){
                q1.push(NULL);
                q2.push(NULL);     
			}
        }
        else if (curr1 == NULL || curr2 == NULL){
            return false;
        }
        else{
            sameLevel1.push_back(curr1->key);
            sameLevel2.push_back(curr2->key);

            if (curr1->left){
                q1.push(curr1->left);
            }
            if (curr1->right){
                q1.push(curr1->right);
            }

            if (curr2->left){
                q2.push(curr2->left);
            }
            if (curr2->right){
                q2.push(curr2->right);
            }
        }
    }
    if(q1.empty() && q2.empty()){
        return true;
    }
    return false;
}
