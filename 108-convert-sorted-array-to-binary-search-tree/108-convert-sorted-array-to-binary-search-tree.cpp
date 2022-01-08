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
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int r = (left + right)/2;
        TreeNode* tree = new TreeNode(nums[r]);
        tree->left = helper(nums, left, r-1);
        tree->right = helper(nums, r+1, right);
        return tree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};