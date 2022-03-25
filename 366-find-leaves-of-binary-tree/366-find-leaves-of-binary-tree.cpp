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
    unordered_map<int,vector<int>> mp;
    int findheight(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            mp[0].push_back(root->val);
            return 0;
        }
        
        int height = 1 + max(findheight(root->left), findheight(root->right));
        mp[height].push_back(root->val);
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return {};
        
        int h = findheight(root);
        vector<vector<int>> ans;
        for(int i = 0; i <= h; i++){
            ans.push_back(mp[i]);
        }
        return ans;        
    }
};