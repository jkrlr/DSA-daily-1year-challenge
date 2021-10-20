// Time = O(N), Space = O(Height)

// DFS - Recursive Sol - It is faster than iterative
// DFS will be helpful when we've to go deeper 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int leftDepth = 1 + maxDepth(root->left);
        int rightDepth = 1 + maxDepth(root->right);
        
        return max(leftDepth, rightDepth);
    }
};