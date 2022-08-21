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
    Node* flatten(Node* head) {
        if(!head) return head;
        //dfs
        Node* nd = new Node(0);
        nd->next = head;
        
        dfs(nd, head);
        nd->next->prev = NULL;
        return nd->next;
    }
    
    Node* dfs(Node* prev, Node* cur){
        if(cur == NULL) return prev;
        cur->prev = prev;
        prev->next = cur;
        
        Node* tem = cur->next;
        Node* flatchild = dfs(cur, cur->child);
        cur->child = NULL;
        
        return dfs(flatchild, tem);
        
    }
};