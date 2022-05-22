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
    vector<int> preorder(Node* root) {
        vector<int> vec;
        stack<Node*> st;
        if(!root)
            return vec;
        
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            vec.push_back(node->val);
            int s = node->children.size();
            for(int i = s-1; i >= 0; i--)
                st.push(node->children[i]);
        }
        
        return vec;
    }
};