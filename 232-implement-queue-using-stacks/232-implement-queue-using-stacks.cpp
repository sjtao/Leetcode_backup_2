class MyQueue {
public:
    stack<int> sf, se;
    MyQueue() {
        
    }
    
    void push(int x) {
        se.push(x);
    }
    
    int pop() {
        while(se.size() > 1){
            sf.push(se.top());
            se.pop();
        }
        int a = se.top();
        se.pop();
        while(!sf.empty()){
            se.push(sf.top());
            sf.pop();
        }
        return a;
    }
    
    int peek() {
        while(se.size() > 1){
            sf.push(se.top());
            se.pop();
        }
        int a = se.top();
        while(!sf.empty()){
            se.push(sf.top());
            sf.pop();
        }
        return a;
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