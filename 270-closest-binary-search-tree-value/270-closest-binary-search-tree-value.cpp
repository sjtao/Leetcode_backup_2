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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        double dis = abs(root->val - target);
        double d;
        while(root){
            d = abs(root->val - target);
            if(d < dis){
                dis = d;
                ans = root->val;
            }
            root = root->val < target ? root->right : root->left;
        }
        return ans;
    }
};