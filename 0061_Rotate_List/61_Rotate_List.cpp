/**
Runtime: 8 ms, faster than 60.86% of C++ online submissions for Rotate List.
Memory Usage: 11.6 MB, less than 88.83% of C++ online submissions for Rotate List.
*/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        ListNode* oldList = head;
        int n = 1;
        while(oldList->next){
            oldList = oldList->next;
            n++;
        }
        k = k % n;
        oldList->next = head;
        
        ListNode*newList = head;
        for(int i = 1; i < n-k; i++){
            newList = newList->next;
        }
        
        ListNode * ans = newList->next;
        newList->next = nullptr;
        
        return ans;        
    }
};
