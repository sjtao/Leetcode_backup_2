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
    vector<int> elem;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        elem.push_back(root->val);
        helper(root->right);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        helper(root);//inorder
        return elem[k-1];
    }
};