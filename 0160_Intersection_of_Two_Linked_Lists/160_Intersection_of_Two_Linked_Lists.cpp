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

/**
Runtime: 56 ms, faster than 37.52% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 17.8 MB, less than 10.57% of C++ online submissions for Intersection of Two Linked Lists.
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> nodeB;
        
        while(headB != NULL){
            nodeB.insert(headB);
            headB = headB->next;
        }
        
        while(headA != NULL){
            if(nodeB.find(headA) != nodeB.end()){
                return headA;
            }
            headA = headA->next;
        }
        
        return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        set<ListNode*> sA;
        while(headA){
            sA.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(sA.find(headB) != sA.end())
                return headB;
            else
                headB = headB->next;
        }
        return NULL;
    }
};
