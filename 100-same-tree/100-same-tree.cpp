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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        queue<TreeNode*> pp, qq;
        pp.push(p);
        qq.push(q);
        while(!pp.empty() && !qq.empty()){
            TreeNode* p1 = pp.front();
            pp.pop();
            TreeNode* q1 = qq.front();
            qq.pop();
            if(p1->val != q1->val)
                return false;
            
            if((!p1->left && q1->left) || (!q1->left && p1->left))
                return false;
            if(p1->left && q1->left){
                qq.push(q1->left);
                pp.push(p1->left);
            }
            
            if((!p1->right && q1->right) || (!q1->right && p1->right))
                return false;
            if(p1->right && q1->right){
                qq.push(q1->right);
                pp.push(p1->right);
            }
            
            
        }
        
        return pp.empty() && qq.empty();
        
    }
};