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
    void dfs(TreeNode* root, int level, vector<vector<int>>& ans){
        vector<int> newlevel;
        if(level >= ans.size()){
            ans.push_back(newlevel);
            ans[level].push_back(root->val);
        }
        else{
            if(level % 2 == 0)
                ans[level].push_back(root->val);
            else
                ans[level].insert(ans[level].begin(), root->val);
        }
        
        if(root->left) dfs(root->left, level+1, ans);
        if(root->right) dfs(root->right, level+1, ans);
        
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        dfs(root, 0, ans);
        return ans;
    }
};