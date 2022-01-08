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
    unordered_map<int, int> mp;
    int i = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int px, int py){
        if(px > py) return NULL;
        int id = preorder[i]; i++;
        TreeNode * tree = new TreeNode(id);
        tree->left = helper(preorder, inorder, px, mp[id]-1);
        tree->right = helper(preorder, inorder, mp[id]+1, py);

        return tree;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]]=i;
        
        return helper(preorder, inorder, 0, inorder.size()-1);
    }
};