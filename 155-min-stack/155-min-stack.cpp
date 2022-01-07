class MinStack {
    
public:
    vector<int> st;
    vector<int> ms;
    
    MinStack() {
        st.resize(0);
        ms.resize(1);
        ms[0] = INT_MAX;
    }
    
    void push(int val) {
        st.push_back(val);
        if(val < ms.back())
            ms.push_back(val);
        else
            ms.push_back(ms.back());
        //ms[end] always the minimal element in this array
    }
    
    void pop() {
        st.pop_back();
        ms.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return ms.back();;
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