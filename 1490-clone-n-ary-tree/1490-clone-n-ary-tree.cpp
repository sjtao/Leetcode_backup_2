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
        queue<pair<Node*, Node*>> q;
        q.push({root, d});
        while(!q.empty()){
            auto np = q.front();
            q.pop();
            Node* old = np.first;
            Node* nwn = np.second;
            for(Node* c : old->children){
                Node* n = new Node(c->val);
                nwn->children.push_back(n);
                q.push({c, n});
            }
        }
        return d;
        
    }
};