
/**
Runtime: 4 ms, faster than 77.57% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.4 MB, less than 41.95% of C++ online submissions for Symmetric Tree.
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
    bool isSymmetricHelper(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) 
            && isSymmetricHelper(t1->left, t2->right) 
            && isSymmetricHelper(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
};

/**
Runtime: 8 ms, faster than 37.18% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.6 MB, less than 17.91% of C++ online submissions for Symmetric Tree.
*/
class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

/**
Runtime: 4 ms
Memory Usage: 16.5 MB
*/
class Solution {
public:
    bool helper(TreeNode *root1, TreeNode *root2){
        if((!root1 && root2) || (root1 && !root2)) return false;
        if(!root1 && !root2) return true;
        
        bool sym = false;
        if(root1->val == root2->val)
            sym = true;
        
        sym = sym && helper(root1->left, root2->right) && helper(root2->left, root1->right);
        
        return sym;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
