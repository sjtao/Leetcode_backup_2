class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return res;
        while(root){
            root = helper(root);
            res.push_back(temp);
            temp.resize(0);
        }
        return res;
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            return NULL;
        }
        root->left = helper(root->left);
        root->right = helper(root->right);
        return root;
    }
};