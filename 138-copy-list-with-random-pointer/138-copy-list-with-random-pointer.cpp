/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node* l1 = head;
        Node* l2 = NULL;
        
        //make a copy after each node
        while(l1){
            l2 = l1->next;
            l1->next = new Node(l1->val);
            l1->next->next = l2;
            l1 = l2;
        }
        //update random pointers
        l1 = head;
        while(l1){
            if(l1->random){
                l1->next->random = l1->random->next;
            }
            l1 = l1->next->next;
        }
        //separate the copied nodes
        l1 = head;
        Node *ans = new Node(0);
        Node *p = ans;
        while(l1){
            p->next = l1->next;
            p = p->next;
            l1->next = l1->next->next;
            l1 = l1->next;
        }
        
        return ans->next;
    }
};