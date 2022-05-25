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
        
        Node* node = new Node(0, NULL, head, NULL);
        Node* cur = node;
        Node* prev = node;
        deque<Node*> s;
        s.push_back(head);
        
        while(!s.empty()){
            cur = s.front();
            s.pop_front();
            prev->next = cur;
            cur->prev = prev;
            
            if(cur->next) s.push_front(cur->next);
            if(cur->child){
                s.push_front(cur->child);
                cur->child = NULL;
            }
            
            prev = cur;
        }
        
        node->next->prev = NULL;
        return node->next;
    }
};