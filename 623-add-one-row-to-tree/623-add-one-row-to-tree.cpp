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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* nd = new TreeNode(val, root, nullptr);
            return nd;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(level < depth-1){
            int s = q.size(); 
            for(int i = 0; i < s; i++){
                TreeNode* nd = q.front();
                q.pop();
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
            
            level ++;
        }
        
        while(!q.empty()){
            TreeNode* nd = q.front();
            q.pop();
            TreeNode* tem = nd->left;
            nd->left = new TreeNode(val, tem, nullptr);
            tem = nd->right;
            nd->right = new TreeNode(val, nullptr, tem);
        }
        
        return root;
    }
};