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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head = head->next;
        }
        
        int l = 0;
        int r = num.size()-1;
        while(l < r){
            if(num[l] == num[r]){
                l++; r--;
            }
            else
                return false;
        }
        return true;
    }
};