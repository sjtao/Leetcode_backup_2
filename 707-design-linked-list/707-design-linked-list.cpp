class MyLinkedList {
public:
    ListNode* head;
    int size;
    MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        ListNode * cur = head->next;
        for(int i = 0; i < index; i++)
            cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        ListNode * cur = head;
        for(int i = 0; i < index; i++)
            cur = cur->next;
        ListNode * add = new ListNode(val);
        add->next = cur->next;
        cur->next = add;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        ListNode * cur = head;
        for(int i = 0; i < index; i++)
            cur = cur->next;
        cur->next = cur->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */