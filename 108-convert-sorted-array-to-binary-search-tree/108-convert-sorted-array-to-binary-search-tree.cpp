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
    vector<int> Nums;
    TreeNode* helper(int left, int right){
        if(left > right) return NULL;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(Nums[mid]);
        root->left = helper(left, mid-1);
        root->right = helper(mid+1, right);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        Nums = nums;
        return helper(0, nums.size()-1);
    }
};