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
    bool bal;
    int height(TreeNode* root){
        if(!root || !bal) return 0;
        int left = height(root->left);
        int right = height(root->right);
        bal = bal && (abs(left-right) <= 1);
        return 1 + max(left, right);
            
    }
    bool isBalanced(TreeNode* root) {
        bal = true;
        height(root);
        return bal;
    }
};