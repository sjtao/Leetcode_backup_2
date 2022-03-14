class MyQueue {
public:
    stack<int> nw, od;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!nw.empty()){
            int y = nw.top();
            nw.pop();
            od.push(y);
        }
        nw.push(x);
        while(!od.empty()){
            int y = od.top();
            od.pop();
            nw.push(y);
        }
    }
    
    int pop() {
        int y = nw.top();
        nw.pop();
        return y;
    }
    
    int peek() {
        return nw.top();
    }
    
    bool empty() {
        return nw.empty();
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