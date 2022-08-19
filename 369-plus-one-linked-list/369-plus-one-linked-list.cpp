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
        ListNode* p = reverseList(head);
        ListNode* q = p;
        int carry = 0;
        q->val = q->val + 1;
        if(q->val >= 10){
            carry = q->val / 10;
            q->val %= 10;
            while(q->next && carry > 0){
                q = q->next;
                int c = (q->val + carry);
                carry = c / 10;
                q->val = c % 10;
            }
            if(carry > 0){
                q->next = new ListNode(carry);
                q = q->next;
            }
            
        }
        
        return reverseList(p);
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};