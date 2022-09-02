class MinStack {
private:
    stack<int> st, stm;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            stm.push(val);
        else
            stm.push(min(stm.top(), val));
        st.push(val);
    }
    
    void pop() {
        st.pop();
        stm.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stm.top();
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