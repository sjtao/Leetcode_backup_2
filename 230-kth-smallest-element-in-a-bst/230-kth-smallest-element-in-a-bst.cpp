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
    priority_queue<int, vector<int>> pq;
    int K;
    void BST_helper(TreeNode* root){
        if(!root) return;
        
        BST_helper(root->left);
        pq.push(root->val);
        if(pq.size() > K)
            pq.pop();      
        BST_helper(root->right);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        BST_helper(root);
        return pq.top();
    }
};