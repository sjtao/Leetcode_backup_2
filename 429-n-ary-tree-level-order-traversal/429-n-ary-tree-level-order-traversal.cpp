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
        vector<vector<int>> vec;
        if(!root)
            return vec;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(Node* a : node->children)
                    q.push(a);
            }
            vec.push_back(temp);
        }
        
        return vec;
    }
};