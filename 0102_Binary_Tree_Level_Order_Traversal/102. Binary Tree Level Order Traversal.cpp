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
Runtime: 8 ms, faster than 34.29% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.6 MB, less than 61.55% of C++ online submissions for Binary Tree Level Order Traversal.
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        vector<int> lvl;
        int curlevel = 0;
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.second == curlevel){
                lvl.push_back(p.first->val);
            }
            else{
                ans.push_back(lvl);
                lvl.clear();
                lvl.push_back(p.first->val);
                curlevel = p.second;
            }
            if(p.first->left) q.push({p.first->left, curlevel+1});
            if(p.first->right) q.push({p.first->right, curlevel+1});  
        }
        ans.push_back(lvl);
        return ans;
    }
};
