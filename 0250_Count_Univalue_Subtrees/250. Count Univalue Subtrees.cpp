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

/**
Runtime: 17 ms, faster than 5.54% of C++ online submissions for Count Univalue Subtrees.
Memory Usage: 16.5 MB, less than 58.44% of C++ online submissions for Count Univalue Subtrees.
*/
class Solution {
public:
    int num = 0;
    bool SubtreesHelper(TreeNode*root){
        if(!root) return false;
        
        if(!root->left && !root->right){
            num += 1; //leaf
            return true;
        }
        
        bool sub = true;
        if(root->left){
           sub = SubtreesHelper(root->left) && sub && (root->val == root->left->val);
        }
        
        if(root->right){           
            sub = SubtreesHelper(root->right) && sub && (root->val == root->right->val);
        }
        
        if(!sub) return false;
        num++;
        return true;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        SubtreesHelper(root);
        return num;
    }
};
