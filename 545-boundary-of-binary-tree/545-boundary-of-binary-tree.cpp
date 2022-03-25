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
    unordered_map<int, vector<int>> mp;
    //0: left
    //1: leaf
    //2: right
    //3: other
    void traverse(TreeNode* root, int flag){
        
        if(!root) return;
        //leaf
        if(!root->left && !root->right){
            mp[1].push_back(root->val);
            return;
        }
        //not leaf
        //left
        if(flag == 0 || flag == 2){
            mp[flag].push_back(root->val);
        }
        
        if(flag == 0){
            traverse(root->left, flag);
            traverse(root->right, root->left ? 3 : flag);
        }
        else if(flag == 2){
            traverse(root->left, root->right ? 3 : flag);
            traverse(root->right, flag);
        }
        else{
            traverse(root->left, 3);
            traverse(root->right, 3);
        }
        
        return;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        ans.push_back(root->val);
        traverse(root->left, 0);
        traverse(root->right, 2);
        for(int i = 0; i < mp[0].size(); ++i)
            ans.push_back(mp[0][i]);
        for(int i = 0; i < mp[1].size(); ++i)
            ans.push_back(mp[1][i]);
        for(int i = mp[2].size()-1; i >= 0; --i)
            ans.push_back(mp[2][i]);
        
        return ans;
    }
};