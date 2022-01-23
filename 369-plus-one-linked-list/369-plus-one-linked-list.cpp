/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *p = new ListNode(0);
        p->next = head;
        ListNode *s = p;
        
        while(head){
            if(head->val != 9) s = head;
            head = head->next;
        }
        
        s->val++;
        s = s->next;
        
        while(s){
            s->val = 0;
            s = s->next;
        }
        
        delete s;
        return p->val != 0 ? p : p->next;
    }
};