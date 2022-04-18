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
    vector<int> vals;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return vals[k-1];
    }
};