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
    unordered_map<TreeNode*, int> mp;
    
    int dp(TreeNode* root){
        if(!root) return 0;
        int l = 0, r = 0;
        if(mp.find(root) == mp.end()){
            if(root->left)
                l = dp(root->left->left) + dp(root->left->right);
            if(root->right)
                r = dp(root->right->left) + dp(root->right->right);
            
            mp[root] = max(root->val + l + r, dp(root->left) + dp(root->right));
        }
        return mp[root];
    }
    int rob(TreeNode* root) {
        return dp(root);
    }
};