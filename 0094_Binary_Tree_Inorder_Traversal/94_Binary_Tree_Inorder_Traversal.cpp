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
//Runtime: 4 ms, faster than 44.23% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage: 8.3 MB, less than 61.60% of C++ online submissions for Binary Tree Inorder Traversal.
class Solution {
public:
    void inoderHelper(TreeNode* root, vector<int>& a){
        if(root == NULL){
            return;
        }
        inoderHelper(root->left, a);
        a.push_back(root->val);
        inoderHelper(root->right, a);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inoderHelper(root, ans);
        return ans;
    }
};
