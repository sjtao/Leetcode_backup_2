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
    Node* cloneTree(Node* root) {
        if(!root) return root;
        Node* d = new Node(root->val);
        for(Node* c : root->children){
            d->children.push_back(cloneTree(c));
        }
        return d;
        
    }
};