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
    bool BST(TreeNode* root, TreeNode* low, TreeNode* high){
        if(!root)
            return true;
        
        if((low && root->val <= low->val) || \
           (high && root->val >= high->val))
            return false;
        
        return BST(root->right, root, high) && BST(root->left, low, root);
    }
    
    bool isValidBST(TreeNode* root) {
        return BST(root, NULL, NULL);
    }
};