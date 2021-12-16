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
 /**
Runtime: 3 ms, faster than 45.69% of C++ online submissions for Middle of the Linked List.
Memory Usage: 7.2 MB, less than 21.30% of C++ online submissions for Middle of the Linked List.
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        queue<ListNode*> qe;
        int len = 0;
        while(head != nullptr){
            qe.push(head);
            head = head->next;
            len += 1;
        }
        int i = 0, mid = len/2;
        while(i < mid){
            qe.pop();
            i++;
        }
        return qe.front();
        
    }
};

/**
Runtime: 8 ms, faster than 5.28% of C++ online submissions for Middle of the Linked List.
Memory Usage: 7.1 MB, less than 21.30% of C++ online submissions for Middle of the Linked List.
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //slow and fast pointers
        ListNode * slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
};
