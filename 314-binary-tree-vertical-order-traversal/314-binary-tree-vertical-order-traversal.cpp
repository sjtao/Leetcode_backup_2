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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<pair<int, TreeNode*>> q;
        vector<pair<int, int>> v;
        int mn = INT_MAX;
        int mx = INT_MIN;
        q.push({0, root});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int idx = p.first;
            mn = min(mn, idx);
            mx = max(mx, idx);
            TreeNode* node = p.second;
            v.push_back({idx, node->val});
            if(node->left) q.push({idx-1, node->left});
            if(node->right) q.push({idx+1, node->right});
        }
        
        vector<vector<int>> ans(mx-mn+1);
        for(auto p : v){
            ans[p.first-mn].push_back(p.second);
        }
        
        return ans;
    }
};