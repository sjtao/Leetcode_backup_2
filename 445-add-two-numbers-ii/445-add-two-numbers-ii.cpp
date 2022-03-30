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
    ListNode* reverse(ListNode* p){
        ListNode* r = NULL;
        ListNode* s = NULL;
        while(p){
            s = new ListNode(p->val);
            s->next = r;
            r = s;
            p = p->next;
        }
        return r;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);
        
        ListNode* cur = NULL;
        ListNode* p = NULL;
        
        int a, b, c, carry = 0;
        while(r1 || r2){
            a = 0;
            b = 0;
            if(r1){
                a = r1->val;
                r1 = r1->next;
            }
            if(r2){
                b = r2->val;
                r2 = r2->next;
            }
            c = a+b+carry;
            cur = new ListNode(c%10);
            cur->next = p;
            p = cur;
            carry = c / 10;
        }
        
        if(carry){
            cur = new ListNode(carry);
            cur->next = p;
            p = cur;
        }
        
        return p;        
    }
};