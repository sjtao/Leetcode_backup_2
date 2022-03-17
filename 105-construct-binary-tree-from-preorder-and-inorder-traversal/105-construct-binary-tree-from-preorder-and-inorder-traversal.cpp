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
    TreeNode* Helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps == pe)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int pivot;
        for(int i = is; i < ie; ++i){
            if(inorder[i] == preorder[ps]){
                pivot = i;
                break;
            }
        }
        
        root->left = Helper(preorder, inorder, ps+1, ps+pivot-is+1, is, pivot);
        root->right = Helper(preorder, inorder, ps+pivot-is+1, pe, pivot+1, ie);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};