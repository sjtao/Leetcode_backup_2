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
Runtime: 44 ms, faster than 49.75% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 34.8 MB, less than 65.50% of C++ online submissions for Search in a Binary Search Tree.
 */
class Solution {
public:
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val){
            return root;
        }
        else if(root->val < val){
            return searchBST(root->right, val);
        }
        else{
            return searchBST(root->left, val);
        }
    }
};
