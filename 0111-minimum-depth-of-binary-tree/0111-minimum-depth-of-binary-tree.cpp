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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            res++;
            for(int i = 0; i < s; i++){
                TreeNode* nd = q.front();
                q.pop();
                if(!nd->left && !nd->right)
                    return res;
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
        
        return res;
    }
};