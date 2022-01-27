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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node->left && node->right){
                ans.push_back(node->right->val);
                q.push(node->right);
            }
            else if(node->left && !node->right){
                ans.push_back(node->left->val);
                q.push(node->left);
            }
            else if(node->left && node->right){
                q.push(node->right);
                q.push(node->left);
            }
        }
        
        return ans;
    }
};