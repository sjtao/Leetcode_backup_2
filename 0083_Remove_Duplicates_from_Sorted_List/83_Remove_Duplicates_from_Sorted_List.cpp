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
 
 //Runtime: 8 ms, faster than 88.71% of C++ online submissions for Remove Duplicates from Sorted List.
//Memory Usage: 11.5 MB, less than 97.34% of C++ online submissions for Remove Duplicates from Sorted List.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        
        ListNode * p = head;

        while(p->next) {
            if(p->val == p->next->val) {
                p->next = p->next->next; 
            }
            else {
                p = p->next;
            }
        }
        
        return head;
    }
};
