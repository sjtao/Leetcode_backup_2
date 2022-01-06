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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* p = new ListNode(-1, head);
        ListNode* h = p;

        while(head && head->next){
            ListNode* f = head;
            ListNode* s = head->next;
            
            h->next = s;
            f->next = s->next;
            s->next = f;
            
            h = f;
            head = f->next;
        }
        
        return p->next;
    }
};