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
    int diam;
    int dfs(Node* root){
        if(!root)
            return 0;
        
        int fm = 0, sm = 0;
        for(Node* c : root->children){
            int m = dfs(c);
            if(m >= fm){
                sm = fm;
                fm = m;
            }
            else if(m >= sm){
                sm = m;
            }
        }
        
        diam = max(diam, fm + sm);
        
        return 1+fm;
        
    }
    
    int diameter(Node* root) {
        if(!root)
            return 0;
        
        diam = 0;
        dfs(root);
        return diam;
    }
};