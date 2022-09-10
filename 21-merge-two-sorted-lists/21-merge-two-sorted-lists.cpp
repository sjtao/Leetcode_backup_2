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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                p->next = new ListNode(list1->val);
                p = p->next;
                list1 = list1->next;
            }
            else{
                p->next = new ListNode(list2->val);
                p = p->next;
                list2 = list2->next;
            }
        }
        
        if(list1)
            p->next = list1;
        else
            p->next = list2;
        p = p->next;
        
        return dummy->next;
    }
};