/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans, *T;
    void inorder(TreeNode* original, TreeNode* cloned){
        if(original == NULL)
            return;
        
        inorder(original->left, cloned->left);
        if(original == T){
            ans = cloned;
            return;
        }
            
        inorder(original->right, cloned->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        T = target;
        inorder(original, cloned);
        return ans;
    }
};