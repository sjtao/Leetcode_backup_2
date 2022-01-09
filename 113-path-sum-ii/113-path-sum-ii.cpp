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
    void dfs(vector<vector<int>>& ans, vector<int>& group,TreeNode* root, int targetSum){
        if(!root) return;
        
        group.push_back(root->val);
        targetSum -= root->val;
        
        if(!root->left && !root->right && targetSum == 0){
            ans.push_back(group);
        }
        
        if(root->left) dfs(ans, group, root->left, targetSum);
        if(root->right) dfs(ans, group, root->right, targetSum);
        group.pop_back();
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        vector<int> group;
        dfs(ans, group, root, targetSum);
        return ans;
    }
};