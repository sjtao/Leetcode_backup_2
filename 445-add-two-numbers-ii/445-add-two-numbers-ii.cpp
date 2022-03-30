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
        stack<int> s1, s2, s3;
        while(l1 || l2){
            if(l1){
                s1.push(l1->val);
                l1 = l1->next;
            }
            if(l2){
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        
        int carry = 0, a, b, c;
        while(!s1.empty() || !s2.empty()){
            a = 0;
            b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            c = a + b + carry;
            s3.push(c%10);
            carry = c / 10;
        }
        if(carry) s3.push(carry);
        
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(!s3.empty()){
            p->next = new ListNode(s3.top());
            s3.pop();
            p = p->next;
        }
        
        return dummy->next;        
    }
};