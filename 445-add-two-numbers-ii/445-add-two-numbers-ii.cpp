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
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
 
        ListNode* p = NULL;
        int a, b, c, carry = 0;
        while(!s1.empty() || !s2.empty() || carry){
            if(s1.empty()){ a = 0;}
            else{
                a = s1.top(); s1.pop();
            }
            if(s2.empty()){ b = 0;}
            else{
                b = s2.top(); s2.pop();
            }
            c = a + b + carry;
            ListNode* cur = new ListNode(c%10);
            cur->next = p;
            p = cur;
            carry = c / 10;
        }
        return p;
    }
};