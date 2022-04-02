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
private:
    vector<int> tree;
    int pos = 0;
    void Inorder(TreeNode* root){
        if(!root) return;
        Inorder(root->left);
        tree.push_back(root->val);
        Inorder(root->right);
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        Inorder(root);
    }
    
    int next() {
        return tree[pos++];
    }
    
    bool hasNext() {
        return pos < tree.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */