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
    bool compare(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        if(left->val != right->val)
            return false;
        
        return compare(left->right, right->left) && compare(left->left, right->right);
    }
    
    bool isSymmetric(TreeNode* root) {  
        return compare(root->left, root->right);
    }
};