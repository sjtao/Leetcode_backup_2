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
 
 /**
 Runtime: 4 ms, faster than 50.69% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.7 MB, less than 38.28% of C++ online submissions for Invert Binary Tree.
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        TreeNode *node = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(node);
        
        return root;
    }
};
