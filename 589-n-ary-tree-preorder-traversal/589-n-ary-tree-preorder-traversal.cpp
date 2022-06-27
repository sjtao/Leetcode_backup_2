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
        stack<Node*> st;
        vector<int> tree;
        if(!root) return tree;
        
        st.push(root);
        while(st.size()>0){
            int s = st.size();
            for(int i = 0; i < s; i++){
                Node* node = st.top();
                st.pop();
                tree.push_back(node->val);
                for(int j = node->children.size()-1; j >= 0; j--)
                    st.push(node->children[j]);
            }
        }
        return tree;
    }
};