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
        
        stack<Node*> dq;
        dq.push(head);
        
        Node* node = new Node(0, NULL, head, NULL);
        Node* cur, * pre = node;
        
        while(!dq.empty()){
            Node* cur = dq.top();
            dq.pop();
            
            cur->prev = pre;
            pre->next = cur;
            
            if(cur->next) dq.push(cur->next);
            if(cur->child){
                dq.push(cur->child);
                cur->child = NULL;
            }
            
            pre = pre->next;
        }
        
        node->next->prev = NULL;
        return node->next;
    }
};