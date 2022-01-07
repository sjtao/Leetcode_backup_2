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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        stack<int> st;
        ListNode* cur = head;
        ListNode* pre;
        ListNode* q = new ListNode(-1);
        ListNode* p = q;
        
        while(cur){
            pre = cur;
            while(cur && st.size()<k){
                st.push(cur->val);
                cur = cur->next;
            }
            if(st.size() == k){
                while(!st.empty()){
                    p->next = new ListNode(st.top());
                    st.pop();
                    p = p->next;
                }
            }
        }
          
        if(!st.empty()){
            p->next = pre;
            p = p->next;
        }
        
        return q->next;
    }
};