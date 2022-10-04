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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, target});
        
        bool res = false;
        while(!q.empty()){
            TreeNode* nd = q.front().first;
            int s = q.front().second - nd->val;
            q.pop();
            if(!nd->left && !nd->right)
                res = res || (s == 0);
            if(nd->left) q.push({nd->left, s});
            if(nd->right) q.push({nd->right, s});
        }
        
        return res;
    }
};