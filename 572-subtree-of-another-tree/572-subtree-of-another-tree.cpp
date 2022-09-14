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
        if((!p && q) || (p && !q))
            return false;
        if(!p && !q)
            return true;
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(isSameTree(n, subRoot))
                return true;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);         
        }
        return false;
    }
};