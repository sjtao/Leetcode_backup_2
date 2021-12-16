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


/**
Runtime: 35 ms, faster than 31.63% of C++ online submissions for Min Stack.
Memory Usage: 16.2 MB, less than 92.80% of C++ online submissions for Min Stack.
*/
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
Runtime: 196 ms
Memory Usage: 16.2 MB
*/
class MinStack {
    
public:
    vector<int> st;
    int size = 0;
    
    MinStack() {
        st.resize(0);
        size = 0;
    }
    
    void push(int val) {
        st.push_back(val);
        size++;
    }
    
    void pop() {
        st.pop_back();
        size--;
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int mi = INT_MAX;
        for(int i = 0; i < size; i++){
            mi = min(st[i],mi);
        }
        return mi;
    }
};
