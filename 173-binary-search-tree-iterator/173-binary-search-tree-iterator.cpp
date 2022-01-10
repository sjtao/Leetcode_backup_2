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
class BSTIterator {
public:
    vector<int> qe;
    int idx = 1, num;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        qe.push_back(root->val);
        inorder(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
        qe.clear();
        qe.push_back(-1);
        inorder(root);
        num = qe.size();
    }
    
    int next() {
        return qe[idx++];
    }
    
    bool hasNext() {
        return idx < num;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */