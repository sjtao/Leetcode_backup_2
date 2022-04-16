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
private:
    void dfs(TreeNode * root, vector <int> &res, bool isLoonely) {
        if(!root) {
            return ;
        }
        if(isLoonely)
            res.push_back(root->val);
        if(root->left && root->right) {
            dfs(root->left, res, false);
            dfs(root->right, res, false);
        }
        else {
            dfs(root->left, res, true);
            dfs(root->right, res, true);
        }        

    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector <int> res;
        dfs(root, res, false);
        return res;    
    }
};