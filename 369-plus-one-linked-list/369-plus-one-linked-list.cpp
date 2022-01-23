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
        ListNode *p = head;
        stack<int> s;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        
        int carry = 1;
        int sum = 0;
        int num;
        
        while(!s.empty()){
            num = s.top(); s.pop();
            sum = num + carry;
            carry = sum / 10;
            p = new ListNode(sum%10, p);
        }
        
        if(carry) p = new ListNode(carry, p);
        
        return p;
    }
};