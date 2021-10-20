// Recursive: Time - O(N), Space - O(Height)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        return isSymmetricTest(root->left, root->right);
    }
    
    bool isSymmetricTest(TreeNode* left, TreeNode* right){
        
        // base case
        if(left==NULL && right == NULL){
            return true;
        }
        else if(left==NULL || right == NULL){
            return false;
        }
        else if(left->val != right->val){
            return false;
        }
        
        // recursive case
        return isSymmetricTest(left->left, right->right) && isSymmetricTest(left->right, right->left);
    }
};

// Iterative: Time - O(N), Space - O(Total No.of leaf Nodes) = O(N) 
// The number of leaf nodes in a full binary tree with n nodes is equal to (N+1)/2.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            
           if(left==NULL && right == NULL){
                continue;
            }
            else if(left==NULL || right == NULL){
                return false;
            }
            else if(left->val != right->val){
                return false;
            }
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
    
};
