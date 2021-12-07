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
Runtime: 21 ms, faster than 13.84% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 69.67% of C++ online submissions for Validate Binary Search Tree.
 */
class Solution {
public:
    bool ValidBSTHelper(TreeNode* root, long low, long high){
        if(!root) return true;
        
        if((root->val <= low) || (root->val >= high))
            return false;
        
        return ValidBSTHelper(root->left, low, root->val) && ValidBSTHelper(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return ValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};

/**
Runtime: 25 ms
Memory Usage: 21.7 MB
*/
class Solution {
public:
    bool ValidBSTHelper(TreeNode* root, TreeNode* low, TreeNode* high){
        if(!root) return true;
        
        if((low && root->val <= low->val) || (high && root->val >= high->val))
            return false;
        
        return ValidBSTHelper(root->left, low, root) && ValidBSTHelper(root->right, root, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return ValidBSTHelper(root, nullptr, nullptr);
    }
};
