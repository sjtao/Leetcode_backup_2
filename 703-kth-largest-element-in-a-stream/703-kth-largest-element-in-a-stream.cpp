class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int n : nums){
            q.push(n);
            if(q.size() > k)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > K)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */