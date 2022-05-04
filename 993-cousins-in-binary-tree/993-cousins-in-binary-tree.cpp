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
    unordered_map<int, pair<int, TreeNode*>> mp;
    int fx, fy;
    void inorder(TreeNode* root, int level){
        if(!root)
            return;
        
        inorder(root->left, level+1);
        if(root->left){
            if(root->left->val == fx ||root->left->val == fy)
                mp[root->left->val] = {level, root};
        }
        if(root->right){
            if(root->right->val == fx ||root->right->val == fy)
                mp[root->right->val] = {level, root};
        }
        inorder(root->right, level+1);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        fx = x;
        fy = y;
        inorder(root, 0);
        
        if(mp.find(x) == mp.end() || mp.find(y) == mp.end())
            return false;
        
        return (mp[x].first == mp[y].first && mp[x].second != mp[y].second);
    }
};