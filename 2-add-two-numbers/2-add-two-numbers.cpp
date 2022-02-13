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
        ListNode* p = new ListNode();
        ListNode* cur = p;
        int a, b, sum, carry = 0;
        while(l1 || l2 || carry){
            a = 0;
            b = 0;
            if(l1) {a = l1->val; l1 = l1->next;}
            if(l2) {b = l2->val; l2 = l2->next;}
            sum = a + b + carry;
            carry = sum / 10;
            cur -> next = new ListNode(sum%10);
            cur = cur->next;
        }

        return p->next;
    }
};