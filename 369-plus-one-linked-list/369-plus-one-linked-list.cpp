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
        stack<int> st;
        
        while(head){
            st.push(head->val);
            head = head->next;
        }
        
        ListNode* p = NULL;
        int carry = 1;
        while(!st.empty()){
            int a = carry + st.top();
            st.pop();
            carry = a / 10;
            ListNode* q = new ListNode(a % 10);
            q->next = p;
            p = q;
        }
        if(carry){
            ListNode* q = new ListNode(carry);
            q->next = p;
            p = q;
        }
        
        return p;
    }
};