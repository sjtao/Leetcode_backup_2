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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while(p){
            p = p->next;
            len++;
        }
        if(len == n) return head->next;
        
        p = head;
        while(len > n+1){
            p = p->next;
            len--;
        }
        
        if(p->next) p->next = p->next->next;
        else p->next = NULL;
        
        return head;
    }
};