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
        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        while(head){
            for(int i = 0; i < m && head; i++){
                p->next = new ListNode(head->val);
                head = head->next;
                p = p->next;
            }
            for(int i = 0; i < n && head; i++){
                head = head->next;
            }
        }
        return ans->next;
    }
};