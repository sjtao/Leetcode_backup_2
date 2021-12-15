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
Runtime: 36 ms, faster than 8.35% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 17.2 MB, less than 36.84% of C++ online submissions for Populating Next Right Pointers in Each Node.
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        //Level Order Traversal, BFS
        queue<Node*> qe;
        qe.push(root);
        while(qe.size() > 0){
            int s = qe.size();
            for(int i = 0; i < s; i++){
                Node *n = qe.front();
                qe.pop();
                if(i != s-1) n->next = qe.front();
                if(n->left)  qe.push(n->left);
                if(n->right)  qe.push(n->right);
            }
        }
        return root;
    }
};

/**
Runtime: 28 ms, faster than 15.99% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 16.9 MB, less than 66.34% of C++ online submissions for Populating Next Right Pointers in Each Node.
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root;
        //Level Order Traversal
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
