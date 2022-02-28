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
    TreeNode* TreeHelper(TreeNode* root){
        if(!root) return root;
        TreeNode* temp = root->left;
        root->left = TreeHelper(root->right);
        root->right = TreeHelper(temp);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return TreeHelper(root);
    }
};