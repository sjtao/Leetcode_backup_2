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
    void helper(TreeNode* root, double target, double& distance, int& ans){
        if(!root) return;
        
        if(root->left) helper(root->left, target, distance, ans);
        
        double d = abs(root->val - target);
        if(d < distance){
            ans = root->val;
            distance = d;
        }
        
        if(root->right) helper(root->right, target, distance, ans);
        return;
    }
    int closestValue(TreeNode* root, double target) {
        double distance = 1e9;
        int ans;
        helper(root, target, distance, ans);
        return ans;
    }
};