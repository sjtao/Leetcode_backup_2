/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node* n = q.front();
                q.pop();
                level.push_back(n->val);
                for(Node* a : n->children)
                    q.push(a);
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};