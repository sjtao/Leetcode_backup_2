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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = findhalf(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode* findhalf(ListNode* head){
        ListNode* mid = NULL;
        while(head && head->next){
            mid = (mid == NULL) ? head : mid->next;
            head = head->next->next;
        }
        ListNode* m = mid->next; //second half
        mid->next = NULL;
        return m;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1) p->next = l1;
        else p->next = l2;
        
        return dummy->next;
    }
};