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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        int a, b, s, carry = 0;
        
        while(l1 || l2){
            a = 0;
            b = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }
            s = a + b + carry;
            carry = s / 10;
            p->next = new ListNode(s % 10);
            p = p->next;
        }
        
        if(carry){
            p->next = new ListNode(carry);
            p = p->next;
        }
        
        return dummy->next;
    }
};