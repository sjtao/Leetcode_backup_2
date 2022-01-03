/**
Runtime: 4 ms, faster than 98.40% of C++ online submissions for Linked List Cycle II.
Memory Usage: 7.5 MB, less than 72.96% of C++ online submissions for Linked List Cycle II.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                slow = head;
                fast = fast;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


/**
Runtime: 16 ms, faster than 18.56% of C++ online submissions for Linked List Cycle II.
Memory Usage: 10 MB, less than 6.07% of C++ online submissions for Linked List Cycle II.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        while(head){
            if(mp.find(head) == mp.end())
                mp[head]++;
            else
                return head;
            head = head->next;
        }
        return NULL;
    }
};

/**
Runtime: 16 ms, faster than 18.56% of C++ online submissions for Linked List Cycle II.
Memory Usage: 10 MB, less than 6.07% of C++ online submissions for Linked List Cycle II.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        while(head){
            if(visited.find(head) != visited.end())
                return head;
            else
                visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
