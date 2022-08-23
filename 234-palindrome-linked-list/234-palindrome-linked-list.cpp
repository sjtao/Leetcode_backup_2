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
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur){
            ListNode* tem = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tem;
        }
        
        return pre;
    }
    
    ListNode* findhalf(ListNode* head){
        ListNode* mid = head;
        while(head->next && head->next->next){
            mid = mid->next;
            head = head->next->next;
        }
        return mid;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findhalf(head);
        ListNode* rev = reverselist(mid->next);
        while(rev){
            if(rev->val != head->val)
                return false;
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};