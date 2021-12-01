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
 /**
Runtime: 32 ms, faster than 60.59% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 11.15% of C++ online submissions for Add Two Numbers.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0, res;
        while(l1 && l2){
            res = carry + l1->val + l2->val;
            carry = res / 10;
            cur->next = new ListNode(res%10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            res = carry + l1->val;
            carry = res / 10;
            cur->next = new ListNode(res%10);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            res = carry + l2->val;
            carry = res / 10;
            cur->next = new ListNode(res%10);
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry){
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        return dummy->next;
    }
};
