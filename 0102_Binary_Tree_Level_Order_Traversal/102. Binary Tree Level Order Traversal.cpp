/**
Runtime: 4 ms, faster than 76.55% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.5 MB, less than 84.49% of C++ online submissions for Binary Tree Level Order Traversal.
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            vector<int> tem_v;
            int qlen = queue.size();
            for(int i = 0; i < qlen; i++){
                TreeNode* curr = queue.front();
                queue.pop_front();
                tem_v.push_back(curr->val);
                if(curr->left) queue.push_back(curr->left);
                if(curr->right) queue.push_back(curr->right);
            }
            ans.push_back(tem_v);
        }
        
        return ans;
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
