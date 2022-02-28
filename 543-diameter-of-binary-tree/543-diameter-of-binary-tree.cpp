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
    int diameter;
    int length(TreeNode* root){
        if(!root) return 0;
        int l = 0, r = 0;
        l = length(root->left);
        r = length(root->right);
        diameter = max(diameter, l+r);
        return 1+max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //dfs
        diameter = 0;
        length(root);
        return diameter;
    }
};