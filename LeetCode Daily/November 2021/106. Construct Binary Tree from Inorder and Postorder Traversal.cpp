// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Medium

// Tags - Binary Tree, Divide and Conquer, Hash-Map

// What this problem wants to teach me?
/* How to write recusive solution by writing the sol for current state
    (for writing the solution for current state, try to convert the logic into code 
    i.e. Look carefully whatever you doing in pen and paper to get the answer from example test cases) and deciding and passing the 
    proper variables change required to pass the function, such that we write the sol for next state easily as we did for current state. */
/* How to construct Unique Binary Tree from Postorder + Inorder or with Preorder + Inorder
    We will use Preorder or Postorder to know the Root and Inorder to know the which elements lie on left subtree, which lie on right subtree
    We can't construct the unique Binary Tree with the help Preorder + Postorder => In this case multiple solutions possible */
/* In any problem, If you see that we will be diving the input into parts
    While getting answer from example test cases than it means it's a divide and conquer problem
    Now, here you can sure this problem will be solved using recursion because divide and conquer problems easily solved by recursion */
/* When their is a lookup step involved while solving a problem, You should always think about HasMap */    

#include<bits/stdc++.h>
using namespace std;

// Divide & Conquer | Time - O(N), Space - O(N + N)-hashmap + depth of recursion
class Solution {
private:
    unordered_map<int,int> inorderMap;
public:
    TreeNode* build(vector<int>& postorder, int& postorderIndex, int inorderLeft, int inorderRight){
        // base case
        if(inorderLeft > inorderRight){
            return nullptr;
        }
        
        // recursive case
        TreeNode *root = new TreeNode(postorder[postorderIndex--]);

        int rootIndex = inorderMap[root->val];

        root->right = build(postorder, postorderIndex, rootIndex + 1, inorderRight);
        root->left = build(postorder, postorderIndex, inorderLeft, rootIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // 1. Map values of inorder traversal to it's array indicies
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorderMap[inorder[i]] = i;
        }
        
        // 2. Build the Tree
        int postorderIndex = postorder.size() - 1;
        return build(postorder, postorderIndex, 0, n-1);
    }
};

// Divide & Conquer | Time - O(N), Space - O(N + N)-hashmap + depth of recursion
// Less Cleaner than above code
class Solution {
private:
    unordered_map<int,int> inorderIndex;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // 1. Map values of inorder traversal to it's array indicies
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorderIndex[inorder[i]] = i;
        }
        
        // 2. Build the Tree
        int postorderIndex = postorder.size() - 1;
        return buildTreeHelper(postorder, postorderIndex, 0, n-1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& postorder, int& postorderIndex, int left, int right){
        // base case
        if(postorderIndex==-1){
            return NULL;
        }
        if(left > right){
            postorderIndex++;
            return NULL;
        }
        if(left==right){
            return new TreeNode(postorder[postorderIndex]);
        }
        
        // recursive case
        TreeNode* root = new TreeNode(postorder[postorderIndex]);
        int mid = inorderIndex[postorder[postorderIndex]];
        
        postorderIndex--;
        root->right = buildTreeHelper(postorder,postorderIndex,mid+1, right);
        
        postorderIndex--;
        root->left = buildTreeHelper(postorder,postorderIndex,left, mid-1);

        return root;
    }
};