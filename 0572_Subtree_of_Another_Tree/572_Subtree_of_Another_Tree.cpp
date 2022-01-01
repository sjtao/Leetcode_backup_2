/**
Runtime: 41 ms, faster than 11.35% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 28.9 MB, less than 55.09% of C++ online submissions for Subtree of Another Tree.
*/
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
    bool identicaltree(TreeNode* s, TreeNode *t){
        if(!s && !t) return true;
        if(!s || !t || s->val != t->val) return false;
        return identicaltree(s->left, t->left) && identicaltree(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root) return false;
        if(identicaltree(root, subroot)) return true;
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};
