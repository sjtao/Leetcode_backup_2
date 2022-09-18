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
    int res;
    void good(TreeNode* root, int m){
        if(!root)
            return;
        
        if(root->val >= m){
            m = root->val;
            res++;
        }
        
        good(root->left, m);
        good(root->right, m);
    }
    
    int goodNodes(TreeNode* root) {
        res = 0;
        good(root, root->val);
        return res;
    }
};