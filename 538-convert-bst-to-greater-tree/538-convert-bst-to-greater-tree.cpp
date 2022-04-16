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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(!st.empty() || node != NULL){
            while(node != NULL){
                st.push(node);
                node = node->right;
            }
            
            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;
            
            node = node->left;
        }
        return root;
    }
};