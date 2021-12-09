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
Runtime: 12 ms, faster than 91.35% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 26.4 MB, less than 45.18% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
*/
class Solution {
private:
    unordered_map<int, int>mp;
    int idx = 0;
public:
    TreeNode* makeTree(int start, int end, vector<int>& preorder, vector<int>& inorder){
        if (start > end) return NULL;
        
        int i = mp[preorder[idx]];
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left  = makeTree(start, i-1, preorder, inorder);
        root->right = makeTree(i+1, end, preorder, inorder);
               
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //inorder: left-node-right
        //preorder: node-left-right
        
        // Create (nodes -> index of inorder array) mapping
        for(int i{}; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        return makeTree(0, inorder.size()-1, preorder, inorder);
    }
};
