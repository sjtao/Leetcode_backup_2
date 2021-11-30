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
 
 /**
 Runtime: 8 ms, faster than 26.74% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.7 MB, less than 74.07% of C++ online submissions for Remove Nth Node From End of List.
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p2 = dummy;
        ListNode *p1 = dummy;
        int i = 0;
        
        while(i <= n){
            p1 = p1->next;
            i++;
        }
        
        while(p1 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
     
        return dummy->next;
    }
};
