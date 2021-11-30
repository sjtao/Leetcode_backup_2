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
Runtime: 24 ms, faster than 46.30% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 15.1 MB, less than 42.49% of C++ online submissions for Remove Linked List Elements.
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *p1 = dummy;
        ListNode *p2 = head;
        
        while(p2){
            if(p2->val == val){
                p1->next = p2->next;
            }
            else{
                p1 = p2;
            }
            
            p2 = p2->next;
        }
        
        return dummy->next;
    }
};
