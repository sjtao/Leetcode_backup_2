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
    vector<vector<int>> ans;
    void pathsum(TreeNode* root, int sum, vector<int> rol){
        if(!root) return;
        sum -= root->val;
        rol.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == 0){  
                ans.push_back(rol);
                return;
            }
        }
        
        pathsum(root->left, sum, rol);
        pathsum(root->right, sum, rol);
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> rol;
        pathsum(root, targetSum, rol);
        return ans;
        
    }
};