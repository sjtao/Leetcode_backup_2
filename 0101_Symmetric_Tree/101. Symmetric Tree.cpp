
/**
Runtime: 4 ms, faster than 77.57% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.4 MB, less than 41.95% of C++ online submissions for Symmetric Tree.
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
    bool isSymmetricHelper(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) 
            && isSymmetricHelper(t1->left, t2->right) 
            && isSymmetricHelper(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
};
