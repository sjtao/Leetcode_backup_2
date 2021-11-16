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
//Runtime: 4 ms, faster than 44.11% of C++ online submissions for Binary Tree Postorder Traversal.
//Memory Usage: 8.6 MB, less than 15.33% of C++ online submissions for Binary Tree Postorder Traversal.
class Solution {
public:
    void postorderHelper(TreeNode* root, vector<int>& a){
        if(root == NULL){
            return;
        }
        postorderHelper(root->left, a);
        postorderHelper(root->right, a);
        a.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }
};
