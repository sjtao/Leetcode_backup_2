/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
 Runtime: 4 ms, faster than 99.74% of C++ online submissions for Linked List Cycle.
Memory Usage: 7.9 MB, less than 81.79% of C++ online submissions for Linked List Cycle.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Floyd's Cycle Finding Algorithm
        if(head == NULL) return false;
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while(slow != fast){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return true;
        
    }
};

/**
Runtime: 12 ms, faster than 71.12% of C++ online submissions for Linked List Cycle.
Memory Usage: 8.1 MB, less than 57.85% of C++ online submissions for Linked List Cycle.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Floyd's Cycle Finding Algorithm
        if(head == NULL) return false;
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while(fast && fast->next){
            if(fast == slow){
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return false;
        
    }
};
