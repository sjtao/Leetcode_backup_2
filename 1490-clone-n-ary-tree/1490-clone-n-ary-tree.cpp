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
        stack<pair<Node*, Node*>> st;
        st.push({root, d});
        while(!st.empty()){
            auto np = st.top();
            st.pop();
            Node* old = np.first;
            Node* nwn = np.second;
            for(Node* c: old->children){
                Node* newchild = new Node(c->val);
                nwn->children.push_back(newchild);
                st.push({c, newchild});
            }
        }
        return d;
        
    }
};