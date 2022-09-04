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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        int mncol = INT_MAX;
        int mxcol = INT_MIN;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int currow = q.front().second.first;
            int curcol = q.front().second.second;
            q.pop();
            mp[curcol][currow].insert(node->val);
            mncol = min(mncol, curcol);
            mxcol = max(mxcol, curcol);
            if(node->left) q.push({node->left, {currow+1, curcol-1}});
            if(node->right) q.push({node->right, {currow+1, curcol+1}});
        }
        
        vector<vector<int>> res;
        for(auto m : mp){
            vector<int> col;
            for(auto t : m.second){
                col.insert(col.end(), t.second.begin(), t.second.end());
            }
            res.push_back(col);
        }
        
        return res;
    }
};