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
        ListNode * dummy = new ListNode();
        ListNode * p = dummy;
        int carry = 0, a, b, c;
        while(l1 || l2){
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            c = a + b + carry;
            carry = c / 10;
            p->next = new ListNode(c % 10);
            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry){
            p->next = new ListNode(carry);
            p = p->next;
        }
        return dummy->next;
    }
};