class MaxStack {
public:
    stack<int> st, mx;
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(mx.empty() || mx.top() <= x)
            mx.push(x);
    }
    
    int pop() {
        int a = st.top();
        st.pop();
        if (a == peekMax()) mx.pop();
        return a;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return mx.top();
    }
    
    int popMax() {
        int m = peekMax();
        stack<int> bf;
        while(top()!=m){
            bf.push(pop());
        }
        pop();
        while(!bf.empty()){
            push(bf.top());
            bf.pop();
        }
        return m;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */