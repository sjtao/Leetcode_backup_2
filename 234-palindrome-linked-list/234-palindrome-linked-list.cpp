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
    ListNode* reverselist(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur  = head;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    ListNode* endoffirst(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode* firsthalf = endoffirst(head);
        ListNode* secondhalf = reverselist(firsthalf->next);
        
        ListNode* p1 = head;
        ListNode* p2 = secondhalf;
        
        while(p2){
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        firsthalf->next = reverselist(secondhalf);
        return true;
    }
    
};