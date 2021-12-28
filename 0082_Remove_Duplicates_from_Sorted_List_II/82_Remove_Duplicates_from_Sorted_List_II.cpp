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
 Runtime: 8 ms, faster than 59.07% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11.2 MB, less than 55.95% of C++ online submissions for Remove Duplicates from Sorted List II.
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode * cur = head;
        ListNode * pre = NULL;
        while(cur && cur->next){
            if(cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                if(!pre){
                    head = cur->next;
                    cur = cur->next;
                }
                else{
                    pre->next = cur->next;
                    cur = cur->next;
                }    
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
        
    }
};
