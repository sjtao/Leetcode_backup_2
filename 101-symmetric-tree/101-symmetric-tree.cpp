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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> sk;
        //# of nodes: 1-1000
        sk.push(root->left);
        sk.push(root->right);
        while(!sk.empty()){
            TreeNode *node1 = sk.top(); sk.pop();
            TreeNode *node2 = sk.top(); sk.pop();
            if((node1 && !node2) || (!node1 && node2))
                return false;
            if(!node1 && !node2)
                continue;
            if(node1->val != node2->val)
                return false;
            sk.push(node1->left);
            sk.push(node2->right);
            sk.push(node1->right);
            sk.push(node2->left);
        }
        return true;
    }
};