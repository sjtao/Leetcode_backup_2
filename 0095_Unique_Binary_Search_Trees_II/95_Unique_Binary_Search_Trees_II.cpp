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
 
 /**
Runtime: 12 ms, faster than 95.64% of C++ online submissions for Unique Binary Search Trees II.
Memory Usage: 15.6 MB, less than 66.61% of C++ online submissions for Unique Binary Search Trees II.
 */
class Solution {
public:
    vector<TreeNode*> TreeHelper(int s, int e){
        if(s > e) return {nullptr};
        if(s == e) return {new TreeNode(s)};
        
        vector<TreeNode*> res;
        for(int i = s; i <= e; i++){
            vector<TreeNode*> left = TreeHelper(s, i-1);
            vector<TreeNode*> right = TreeHelper(i+1, e);
            for(auto l:left){
                for(auto r:right){
                    res.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return TreeHelper(1,n);
    }
};
