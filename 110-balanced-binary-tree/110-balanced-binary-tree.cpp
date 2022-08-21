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
    bool balance;
    int hight(TreeNode* root){
        if(!root) return 0;
        int left = hight(root->left);
        int right = hight(root->right);
        balance = balance && (abs(left-right) <= 1);
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        balance = true;
        hight(root);
        return balance;
    }
};