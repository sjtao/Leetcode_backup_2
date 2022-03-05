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
    TreeNode* Helper(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int m = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = Helper(nums, left, m-1);
        node->right = Helper(nums, m+1, right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * ans;
        ans = Helper(nums, 0, nums.size()-1);
        return ans;
    }
};