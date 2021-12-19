/**
Runtime: 70 ms, faster than 7.43% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 33 MB, less than 24.66% of C++ online submissions for Merge Two Binary Trees.
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
    TreeNode* mergeHepler(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        
        TreeNode * tree = new TreeNode(root1->val + root2->val);
        tree->left = mergeHepler(root1->left, root2->left);
        tree->right = mergeHepler(root1->right, root2->right);
        
        return tree;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeHepler(root1, root2);
    }
};
