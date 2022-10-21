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
    int res;
    void depth(TreeNode* root, int d){
        if(root && !root->left && !root->right){
            res = min(res, d);
            return;
        }
        
        if(root->left) depth(root->left, d+1);
        if(root->right) depth(root->right, d+1);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        res = INT_MAX;
        depth(root, 1);
        return res;
    }
};