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

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        
        while(!q.empty()){
            TreeNode* nd = q.front().first;
            int m = q.front().second;
            q.pop();
            if(nd->val >= m){
                res++;
                m = nd->val;
            }
            if(nd->left) q.push({nd->left, m});
            if(nd->right) q.push({nd->right, m});
        }
        return res;
    }
};