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
    vector<vector<int>> res;
    
    void path(TreeNode* root, vector<int> p, int sum){
        if(!root) return;
        
        sum -= root->val;
        p.push_back(root->val);
        
        if(!root->left && !root->right && sum == 0) //root-to-leaf
            res.push_back(p);
        
        path(root->left, p, sum);
        path(root->right, p, sum);
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> p;
        path(root, p, targetSum);
        return res;
    }
};