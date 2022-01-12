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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else{
            TreeNode* newtree = nullptr;
            if(!root->left)
                newtree = root->right;
            else if(!root->right)
                newtree = root->left;
            else{
                //find the min node in right subtree
                TreeNode* parent = root;
                newtree = root->right;
                while(newtree->left){
                    parent = newtree;
                    newtree = newtree->left;
                }
                if(parent != root){
                    parent->left = newtree->right;
                    newtree->right = root->right;
                }
                newtree->left = root->left;
            }
            
            delete root;
            return newtree;
        }
        
        return root;
    }
};