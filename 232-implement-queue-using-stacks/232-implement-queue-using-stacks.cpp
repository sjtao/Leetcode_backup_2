class MyQueue {
public:
    stack<int> sf, se;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!se.empty()){
            sf.push(se.top());
            se.pop();
        }
        se.push(x);
        while(!sf.empty()){
            se.push(sf.top());
            sf.pop();
        }
    }
    
    int pop() {
        int a = se.top();
        se.pop();
        return a;
    }
    
    int peek() {
        return se.top();;
    }
    
    bool empty() {
        return se.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */