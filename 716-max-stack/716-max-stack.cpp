class MaxStack {
public:
    stack<int> st, mx;
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(mx.empty()){
            mx.push(x);
        }
        else{
            stack<int> bu;
            while(!mx.empty() && mx.top() > x){
                bu.push(mx.top());
                mx.pop();
            }
            mx.push(x);
            while(!bu.empty()){
                mx.push(bu.top());
                bu.pop();
            }
        }
    }
    
    int pop() {
        int a = st.top();
        st.pop();
        stack<int> bf;
        while(mx.top()!=a){
            bf.push(mx.top());
            mx.pop();
        }
        mx.pop();
        while(!bf.empty()){
            mx.push(bf.top());
            bf.pop();
        }
        return a;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return mx.top();
    }
    
    int popMax() {
        int m = mx.top();
        mx.pop();
        stack<int> bf;
        while(st.top()!=m){
            bf.push(st.top());
            st.pop();
        }
        st.pop();
        while(!bf.empty()){
            st.push(bf.top());
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