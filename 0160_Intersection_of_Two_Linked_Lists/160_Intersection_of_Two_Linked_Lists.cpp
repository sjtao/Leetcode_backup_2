/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
 Runtime: 40 ms, faster than 88.15% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.7 MB, less than 31.34% of C++ online submissions for Intersection of Two Linked Lists.
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while(pA != pB){
            if(pA == NULL){
                pA = headB;
            }
            else{
                pA = pA->next;
            }
            if(pB == NULL){
                pB = headA;
            }
            else{
                pB = pB->next;
            }
        }
        return pA;
    }
};
