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

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        //bfs
        unsigned long width = 0;
        queue<pair<TreeNode*, unsigned long>> q;
        q.push({root,1});
        unsigned long l, r;
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            l = q.front().second;
            for(int i = 0; i < s; i++){
                TreeNode* nd = q.front().first;
                r = q.front().second;
                q.pop();
                
                if(nd->left) q.push({nd->left, 2*(r-l)});
                if(nd->right) q.push({nd->right, 2*(r-l)+1});
            }
            width = max(width, r - l + 1);
            level++;
        }
        return width;
    }
};