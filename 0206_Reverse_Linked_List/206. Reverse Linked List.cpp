/**
Runtime: 4 ms, faster than 95.43% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 78.55% of C++ online submissions for Reverse Linked List.
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        while(cur!=NULL){
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        return prev;
    }
};
