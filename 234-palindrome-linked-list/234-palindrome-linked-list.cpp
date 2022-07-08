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
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = head;
        slow = reverse(slow);
        
        while(slow){
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};