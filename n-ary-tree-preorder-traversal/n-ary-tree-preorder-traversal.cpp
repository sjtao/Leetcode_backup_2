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
    vector<int> vec;
    void pre(Node* root){
        if(!root)
            return;
        vec.push_back(root->val);
        for(Node* n : root->children)
            pre(n);
        return;
    }
    vector<int> preorder(Node* root) {
        pre(root);
        return vec;
    }
};