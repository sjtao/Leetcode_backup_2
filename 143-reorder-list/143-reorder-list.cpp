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
    void reorderList(ListNode* head) {
        deque<int> qe;
        ListNode *dummy = head->next;
        while(dummy){
            qe.push_back(dummy->val);
            dummy = dummy->next;
        }
        
        dummy = head;
        while(qe.size()){
            dummy->next = new ListNode(qe.back());
            dummy = dummy->next;
            qe.pop_back();
            
            if(qe.size()>0){
                dummy->next = new ListNode(qe.front());
                dummy = dummy->next;
                qe.pop_front();
            }
        }
        
        dummy = NULL;
        return;
    }
};