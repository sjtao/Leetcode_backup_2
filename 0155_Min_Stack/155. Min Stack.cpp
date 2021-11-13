//Runtime: 20 ms, faster than 88.26% of C++ online submissions for Min Stack.
//Memory Usage: 16.4 MB, less than 70.19% of C++ online submissions for Min Stack.

class MinStack {
public:
    
    stack<int> ms1, ms2;

    MinStack() {
        
    }
    
    void push(int val) {
        //pushes the element val onto the stack
        ms1.push(val);
        if(ms2.empty() || val <= ms2.top()){
            ms2.push(val);
        }
    }
    
    void pop() {
        //removes the element on the top of the stack
        if(ms1.top() == ms2.top())
            ms2.pop();
        ms1.pop();
    }
    
    int top() {
        return ms1.top();
    }
    
    int getMin() {
        return ms2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
