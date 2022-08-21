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
        
        deque<Node*> dq;
        dq.push_back(head);
        
        Node* node = new Node(0, NULL, head, NULL);
        Node* cur, * pre = node;
        
        while(!dq.empty()){
            Node* cur = dq.front();
            dq.pop_front();
            
            cur->prev = pre;
            pre->next = cur;
            
            if(cur->next) dq.push_front(cur->next);
            if(cur->child){
                dq.push_front(cur->child);
                cur->child = NULL;
            }
            
            pre = pre->next;
        }
        
        node->next->prev = NULL;
        return node->next;
    }
};