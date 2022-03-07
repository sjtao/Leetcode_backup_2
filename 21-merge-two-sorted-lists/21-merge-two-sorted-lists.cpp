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
        ListNode* d = new ListNode(0);
        ListNode* p = d;
        while(list1 || list2){
            int a = list1 == NULL ? INT_MAX : list1->val;
            int b = list2 == NULL ? INT_MAX : list2->val;
            if(a < b){
                p->next = new ListNode(a);
                list1 = list1->next;
            }
            else{
                p->next = new ListNode(b);
                list2 = list2->next;
            }
            p = p->next;
        }
        return d->next;
    }
};