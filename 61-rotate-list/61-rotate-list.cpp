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
        if(!head || !head->next) return head;
        
        //count list length
        ListNode* p = head;
        int len = 1;
        while(p->next){
            len++;
            p = p->next;
        }
        p->next = head; //cycle        
        
        k %= len;
        ListNode* q1 = head;
        for(int i = 0; i < len-1-k; i++)
            q1 = q1->next;
        
        ListNode* q2 = q1->next;
        q1->next = NULL;
        
        return q2;
    }
};