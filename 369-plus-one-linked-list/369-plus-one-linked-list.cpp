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
        
        int carry = 1;
        ListNode* ans = NULL;
        while(!st.empty()){
            carry += st.top();
            st.pop();
            ListNode* p = new ListNode(carry%10);
            p->next = ans;
            ans = p;
            carry /= 10; 
        }
        
        if(carry){
            ListNode* p = new ListNode(carry);
            p->next = ans;
            ans = p;
        }
        
        return ans;
    }
};