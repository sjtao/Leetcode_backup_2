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
    ListNode* findsecond(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* prev = reverse(head->next);
        head->next->next = head;
        head->next = NULL;  
        return prev;        
    }
    
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        while(p2->next){
            ListNode* tem = p1->next;
            p1->next = p2;
            p1 = tem;
            
            tem = p2->next;
            p2->next = p1;
            p2 = tem;
        }
        return p1;
    }
    
    void reorderList(ListNode* head) {
        //find the second half
        //reverse the second half
        //merge first & second half
        if(!head || !head->next)
            return;
        ListNode* second = findsecond(head);
        ListNode* rev_second = reverse(second);
        head = merge(head, rev_second);
        return;
    }
};