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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        int len = 0;
        ListNode* p = head;
        while(p){
            len++;
            p = p->next;
        }
        
        k %= len;
        if(k == 0)
            return head;
        
        int l = len;
        p = head;
        while(l > k){
            p = p->next;
            l--;
        }
        ListNode * q = p;
        while(p->next){
            p = p->next;
        }
        p->next = head;
        
        while(l < len){
            p = p->next;
            l++;
        }
        p->next = NULL;
        p = p->next;
        return q;
    }
};