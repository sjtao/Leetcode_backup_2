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
    int depth(Node* root){
        if(!root)
            return 0;
        int m = -1;
        for(Node* c : root->children)
            m = max(m, depth(c));
        return 1+m;
    }
    
    int maxDepth(Node* root) {
        if(!root) return 0;
        return 1+depth(root);
    }
};