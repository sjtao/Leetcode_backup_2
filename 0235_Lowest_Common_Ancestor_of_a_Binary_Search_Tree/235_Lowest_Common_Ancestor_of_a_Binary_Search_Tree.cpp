

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
Runtime: 20 ms, faster than 99.32% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.2 MB, less than 61.36% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        if(pval > qval) return lowestCommonAncestor(root, q, p);
        
        while(root){
            if(pval > root->val)
                root = root->right;
            if(qval < root->val)
                root = root->left;
            if(pval <= root->val && qval >= root->val)
                break;
        }
        return root;
    }
};
