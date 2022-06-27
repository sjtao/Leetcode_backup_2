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
    vector<vector<int>> tree;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        
        if(tree.size() == level)
            tree.push_back(vector<int>());
        
        tree[level].push_back(root->val);
        if(root->left) dfs(root->left, level+1);
        if(root->right) dfs(root->right, level+1);
        
        return;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return tree;
        
        dfs(root, 0);
        return tree;
    }
};