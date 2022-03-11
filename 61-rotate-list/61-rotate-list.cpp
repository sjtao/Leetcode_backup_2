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
        
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head = head->next;
        }
        
        int n = num.size();
        k %= n;
        
        ListNode* p = new ListNode();
        ListNode* q = p;
        for(int i = 0; i < n; ++i){
            q->next = new ListNode(num[(n-k+i)%n]);
            q = q->next;
        }
        
        return p->next;
    }
};