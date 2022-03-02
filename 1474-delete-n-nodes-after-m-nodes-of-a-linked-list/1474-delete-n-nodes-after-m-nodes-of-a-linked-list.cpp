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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(!head) return NULL;
        ListNode *q = head;
        ListNode *p = head;
        while(p){
            for(int i = 0; i < m && p; i++){
                q = p;
                p = p->next;
            }
            for(int i = 0; i < n && p; i++){
                p = p->next;
            }
            q->next = p;
        }
        return head;
    }
};