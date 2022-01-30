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
    vector<vector<int>> ans;
    int height(TreeNode* root){
        if(!root) return 0;
        int level = max(height(root->left), height(root->right))+1;
        if(ans.size() < level) ans.push_back(vector<int>());
        ans[level-1].push_back(root->val);
        return level;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        //dfs
        height(root); 
        return ans;
    }
};