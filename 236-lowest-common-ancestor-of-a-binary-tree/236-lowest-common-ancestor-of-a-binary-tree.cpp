/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return false;
        //dfs
        int cur = (root == p || root == q) ? 1 : 0;
        int left = helper(root->left, p, q) ? 1 : 0;
        int right = helper(root->right, p, q) ? 1 : 0;
        int s = cur + left + right;
        if(s >=2)
            ans = root;
        return s > 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};