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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        
        head = new ListNode();
        ListNode * p = head;
        while(!st.empty()){
            p->next = new ListNode(st.top());
            st.pop();
            p = p->next;
        }
        
        return head->next;
    }
};