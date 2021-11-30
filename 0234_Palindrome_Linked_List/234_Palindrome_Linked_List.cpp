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
Runtime: 196 ms, faster than 78.23% of C++ online submissions for Palindrome Linked List.
Memory Usage: 128.3 MB, less than 11.45% of C++ online submissions for Palindrome Linked List.
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> n;
        while(head){
            n.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = n.size()-1;
        while(i < j){
            if(n[i] != n[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
