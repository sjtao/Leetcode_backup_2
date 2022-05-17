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
    vector<int> lone;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(!root->left && root->right)
            lone.push_back(root->right->val);
        if(root->left && !root->right)
            lone.push_back(root->left->val);
        inorder(root->right);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        inorder(root);
        return lone;
    }
};