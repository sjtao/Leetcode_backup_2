/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/**
Runtime: 22 ms, faster than 13.25% of C++ online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 17.6 MB, less than 41.83% of C++ online submissions for Populating Next Right Pointers in Each Node II.
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node *s = q.front();
                q.pop();
                if(i != n-1) s->next = q.front();
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right); 
            }
        }
        
        return root;
    }
};
