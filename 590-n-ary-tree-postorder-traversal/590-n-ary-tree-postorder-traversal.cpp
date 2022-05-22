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
    
    vector<int> postorder(Node* root) {
        vector<int> vec;
        if(!root)
            return vec;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            for(Node* n : node->children)
                st.push(n);
            vec.push_back(node->val);
        }
        reverse(vec.begin(), vec.end());
        
        return vec;
    }
};