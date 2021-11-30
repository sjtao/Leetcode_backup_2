/**
Runtime: 4 ms, faster than 95.43% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 78.55% of C++ online submissions for Reverse Linked List.
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
//iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        while(cur!=NULL){
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        return prev;
    }
};

/**
Runtime: 8 ms, faster than 63.50% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.5 MB, less than 20.21% of C++ online submissions for Reverse Linked List.
*/
//stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        stack<ListNode*> s;
        
        while(head!=nullptr){
            ListNode* temp = head;
            s.push(head);
            head = head->next;
            temp->next = nullptr;
        }
        
        ListNode * dummy = new ListNode();
        ListNode * a = dummy;
        while(!s.empty()){
            a->next = s.top();
            a = a->next;
            s.pop();   
        }
        
        return dummy->next;
    }
};

/**
Runtime: 8 ms, faster than 63.50% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.5 MB, less than 10.58% of C++ online submissions for Reverse Linked List.
*/
//recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //base case
        if(! head|| ! head->next) return head;
        
        //recursive case
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return node;
        
    }
};
