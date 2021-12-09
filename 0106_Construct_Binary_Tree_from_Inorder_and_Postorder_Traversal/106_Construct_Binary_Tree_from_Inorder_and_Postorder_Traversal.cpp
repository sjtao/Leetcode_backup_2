//Runtime: 43 ms, faster than 16.37% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage: 26.4 MB, less than 49.82% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.

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
    unordered_map<int, int>mp;
    TreeNode* makeTree(int start, int end, int &idx, vector<int>& postorder, vector<int>& inorder){
        if (start > end) return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;
        int i = mp[root->val];
        root->right = makeTree(i+1, end, idx, postorder, inorder);
        root->left  = makeTree(start, i-1, idx, postorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder: left-node-right
        //postorder: left-right-node
        
        int idx = postorder.size()-1;
        // Create (nodes -> index of inorder array) mapping
        for(int i{}; i<inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        
        return makeTree(0, inorder.size()-1, idx, postorder, inorder);
    }
};
