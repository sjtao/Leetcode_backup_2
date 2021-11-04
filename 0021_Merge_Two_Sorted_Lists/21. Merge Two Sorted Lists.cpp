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

//Runtime: 12 ms, faster than 39.05% of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage: 14.9 MB, less than 54.12% of C++ online submissions for Merge Two Sorted Lists.
class Solution {
public:
    ListNode* mergeHelper(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        //recursive
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeHelper(l1, l2);
    }
};

//Runtime: 8 ms, faster than 75.36% of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage: 14.7 MB, less than 88.92% of C++ online submissions for Merge Two Sorted Lists.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *merge = new ListNode();
        ListNode  *temp = merge;

        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        if(l1){
            temp->next = l1;
        }
        
        if(l2){
            temp->next = l2;
        }
        //temp->next = (l1 == NULL) ? l2 : l1; similar runtime
        return merge->next;
        
    }
};
