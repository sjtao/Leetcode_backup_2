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
    vector<int> ans;
    vector<int> getLonelyNodes(TreeNode* root) {
        if(!root)
            return ans;
        
        if(!root->left && root->right){
            ans.push_back(root->right->val);            
        }
        if(root->left && !root->right){
            ans.push_back(root->left->val);
        }
        getLonelyNodes(root->left);
        getLonelyNodes(root->right);
        return ans;
    }
};