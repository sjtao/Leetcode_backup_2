/**
Runtime: 8 ms, faster than 88.47% of C++ online submissions for Path Sum.
Memory Usage: 21.5 MB, less than 38.25% of C++ online submissions for Path Sum.
*/
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        stack<TreeNode*> r;
        stack<int> s;
        
        r.push(root);
        s.push(targetSum);
        
        while(!r.empty()){
            TreeNode* t = r.top();
            r.pop();
            int c = s.top()-t->val;
            s.pop();
            if(!t->left && !t->right && c == 0){
                return true;
            }
            if(t->left){
                r.push(t->left);
                s.push(c);
            }
            if(t->right){
                r.push(t->right);
                s.push(c);
            }
        }
        return false;
    }
};

/**
12 ms
*/
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum -= root->val;
        if(!root->left && !root->right) return (targetSum == 0);
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);    
    }
};
