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
    vector<int> num;
    TreeNode* BST_helper(int left, int right){
        if(left > right) return NULL;
        //preorder
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = BST_helper(left, mid-1);
        root->right = BST_helper(mid+1,right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        num = nums;
        return BST_helper(0, nums.size()-1);
    }
};