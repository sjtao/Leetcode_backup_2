/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepthHelper(TreeNode *root){
        if(!root) return 0;
        
        int dl = maxDepthHelper(root->left);
        int dr = maxDepthHelper(root->right);
        return max(dl, dr) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root);
    }
};
