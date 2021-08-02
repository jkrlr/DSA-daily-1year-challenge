// Time = O(N)-traversing all the nodes, Space=(N)-storing the map

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

//helper
void traverseTree(node *root, int dist, map<int,vector<int>> &m){
    // base case
    if(root==NULL){
        return;
    }

    // recurive case
    m[dist].push_back(root->data);  // insert the data into map at key=dist
    
    traverseTree(root->left, dist - 1, m);
    traverseTree(root->right, dist + 1, m);
}

void verticalOrderPrint(node *root){
    map<int, vector<int>> m;
    int dist = 0;

    traverseTree(root, dist, m);

    // Keys are sorted (-2,-1,0,1,2,3...)
    for(auto p:m){
        int key = p.first;
        vector<int> line = p.second;

        for(int data:line){
            cout << data << " ";
        }
        cout << endl;
    }
}