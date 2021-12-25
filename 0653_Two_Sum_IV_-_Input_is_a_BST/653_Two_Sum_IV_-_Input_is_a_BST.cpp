/**
Runtime: 32 ms, faster than 89.05% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 36.8 MB, less than 79.79% of C++ online submissions for Two Sum IV - Input is a BST.
*/
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inorder(root, list); //list is a sorted vector
        int i = 0, j = list.size()-1;
        while(i < j){
            int sum = list[i] + list[j];
            if(sum > k) j--;
            else if(sum < k) i++;
            else return true;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& list){
        if(!root) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
};
