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
 
 //Runtime: 4 ms, faster than 98.52% of C++ online submissions for Path Sum.
//Memory Usage: 21.3 MB, less than 38.03% of C++ online submissions for Path Sum.
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        if(root->left == NULL && root->right == NULL){
            if (targetSum == root->val) return 1;
            else                        return 0;
        }
        else{
            targetSum -= root->val;
            bool left = hasPathSum(root->left, targetSum);
            bool right = hasPathSum(root->right, targetSum);
            return left || right;
        }
        
    }
};
