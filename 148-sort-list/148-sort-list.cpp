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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        
        sort(v.begin(), v.end());
        
        head = new ListNode();
        ListNode* q = head;
        for(int n : v){
            q->next = new ListNode(n);
            q = q->next;
        }
        
        return head->next;
    }
};