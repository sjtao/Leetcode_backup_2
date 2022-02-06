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
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        vector<int> t;
        
        while(!q.empty()){
            int s = q.size();
            while(s > 0){
                Node * node = q.front();
                q.pop();
                t.push_back(node->val);
                for(auto i : node->children){
                    q.push(i);
                }
                s--;
            }
            ans.push_back(t);
            t.clear();            
        }
        
        return ans;
    }
};