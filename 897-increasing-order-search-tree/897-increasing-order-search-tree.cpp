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
        if(!root)
            return;
        
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* ans = new TreeNode(0);
        TreeNode* cur = ans;
        for(int v : vals){
            cur->right = new TreeNode(v);
            cur = cur->right;
        }
        return ans->right;
    }
};