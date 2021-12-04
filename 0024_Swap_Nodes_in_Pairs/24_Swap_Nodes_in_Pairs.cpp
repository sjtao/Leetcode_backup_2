/**
Runtime: 4 ms, faster than 58.96% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.6 MB, less than 52.69% of C++ online submissions for Swap Nodes in Pairs.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *nodeone = head;
        ListNode *nodetwo = head->next;
        
        nodeone->next = swapPairs(nodetwo->next);
        nodetwo->next = head;
        
        return nodetwo;
    }
};
