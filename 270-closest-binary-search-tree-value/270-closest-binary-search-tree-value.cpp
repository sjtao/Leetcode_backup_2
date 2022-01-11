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
    int closestValue(TreeNode* root, double target) {
        int val;
        int closet = root->val;
        while(root){
            val = root->val;
            closet = abs(val-target) < abs(closet-target) ? val : closet;
            if(root->val > target) root = root->left;
            else root = root->right;
        }
        return closet;
    }
};