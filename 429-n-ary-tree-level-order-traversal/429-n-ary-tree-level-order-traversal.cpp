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
        vector<vector<int>> res;
        if(!root) return res;
        
        vector<int> bfs;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node* nd = q.front();
                q.pop();
                bfs.push_back(nd->val);
                for(Node* n : nd->children)
                    q.push(n);
            }
            res.push_back(bfs);
            bfs.clear();
        }
        
        return res;
    }
};