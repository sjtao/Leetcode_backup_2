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
    int helper(TreeNode* root, bool left){
        if(!root->left && !root->right){
            return left ? root->val : 0;
        }
        
        int s = 0;
        if(root->left)
            s += helper(root->left, true);
        if(root->right)
            s += helper(root->right, false);
        
        return s;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return helper(root, false);
    }
};