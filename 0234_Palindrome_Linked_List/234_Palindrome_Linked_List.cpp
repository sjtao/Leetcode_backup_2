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
//time and space: O(n) 
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


/**
Runtime: 172 ms, faster than 94.18% of C++ online submissions for Palindrome Linked List.
Memory Usage: 116.3 MB, less than 63.48% of C++ online submissions for Palindrome Linked List.
*/
class Solution {
public:
    
    ListNode *FindFirstHalf(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode * ReverseList(ListNode * head){
        if (!head || !head->next) return head;
        
        ListNode *node = ReverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return node;        
    }
    
    
    bool isPalindrome(ListNode* head) {
        //reverse the seond half and compare to the first half
        if(!head) return true;
        
        ListNode* firstend = FindFirstHalf(head);
        ListNode* rvsecond = ReverseList(firstend->next);
        
        ListNode *f = head, *s = rvsecond;
        while(s){
            if(f->val != s->val){
                return false;
            }
            f = f->next;
            s = s->next;
        }
        
        return true;
    }
};
