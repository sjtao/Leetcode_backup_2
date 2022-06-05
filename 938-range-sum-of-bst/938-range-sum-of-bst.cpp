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
    int sum, L, H;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        if(root->val >= L && root->val <= H)
            sum += root->val;
        inorder(root->right);
        return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        L = low;
        H = high;
        inorder(root);
        return sum;
    }
};