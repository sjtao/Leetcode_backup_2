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
 //Runtime: 12 ms, faster than 76.15% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
//Memory Usage: 21.4 MB, less than 76.57% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
class Solution {
public:
    TreeNode* BSTHelper(vector<int>& nums, int start, int end){
        if(end < start) return NULL;
        if(end == start)
        {
            TreeNode *newNode=new TreeNode(nums[start]);
            return newNode;
        }
        
        int mid = start + (end - start) / 2;    
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = BSTHelper(nums, start, mid-1);
        root->right = BSTHelper(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTHelper(nums, 0, nums.size()-1);
    }
};
