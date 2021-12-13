/**
Runtime: 24 ms, faster than 69.76% of C++ online submissions for Design Circular Queue.
Memory Usage: 16.9 MB, less than 51.37% of C++ online submissions for Design Circular Queue.
*/

class MyCircularQueue {
private:
    vector<int> queue;
    int q_head, q_tail;
    int size;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        q_head = 0;
        q_tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        q_tail = (q_tail + 1) % size;
        queue[q_tail] = value;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(q_head == q_tail){
            q_head = 0;
            q_tail = -1;
        }
        else{
            q_head = (q_head + 1) % size;
        }
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[q_head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[q_tail];
    }
    
    bool isEmpty() {       
        return q_tail == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (q_tail + 1) % size == q_head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
