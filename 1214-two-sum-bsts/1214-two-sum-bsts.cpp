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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> st;
        queue<TreeNode*> q;
        q.push(root1);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            st.insert(target - node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        q.push(root2);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(st.count(node->val))
                return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return false;
    }
};