/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* prev, Node* cur){
        if(!cur) return prev;
        cur->prev = prev;
        prev->next = cur;
        
        Node* temp = cur->next;
        Node* tail = dfs(cur, cur->child);
        cur->child = NULL;
        
        return dfs(tail, temp);
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node* node = new Node(0, NULL, head, NULL);
        dfs(node, head);
        node->next->prev = NULL;
        return node->next;
    }
};