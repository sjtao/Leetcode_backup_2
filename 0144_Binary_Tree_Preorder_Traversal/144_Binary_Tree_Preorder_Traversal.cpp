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

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
//Memory Usage: 8.5 MB, less than 15.01% of C++ online submissions for Binary Tree Preorder Traversal.
class Solution {
public:
    void preoderHelper(TreeNode* root, vector<int>& a){
        if(root == NULL){
            return;
        }
        a.push_back(root->val);
        preoderHelper(root->left, a);
        preoderHelper(root->right, a);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preoderHelper(root, ans);
        return ans;
    }
};
