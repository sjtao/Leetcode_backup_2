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
        ListNode* p = new ListNode();
        ListNode* cur = p;
        while(list1 && list2){
            int a = list1->val;
            int b = list2->val;
            if(a < b){
                cur->next = new ListNode(a);
                list1 = list1->next;
            }
            else{
                cur->next = new ListNode(b);
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        cur->next = list1==NULL ? list2 : list1;
        cur = cur->next;
        
        return p->next;
    }
};