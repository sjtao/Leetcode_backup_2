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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        
        while(head && head->next){
            ListNode* p1 = head;
            ListNode* p2 = head->next;
            
            //swap
            p->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            
            p = p1;
            head = p1->next;
        }
        return dummy->next;
    }
};