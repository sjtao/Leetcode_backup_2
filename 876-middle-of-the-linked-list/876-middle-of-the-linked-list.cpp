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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        int n = 0;
        ListNode * p = head;
        while(p){
            n++;
            p = p->next;
        }
        
        p = head;
        int mid = n / 2;
        while(mid > 0){
            p = p->next;
            mid--;
        }
        
        return p;
    }
};