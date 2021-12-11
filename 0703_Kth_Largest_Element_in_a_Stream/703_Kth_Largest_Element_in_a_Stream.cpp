/**
Runtime: 28 ms, faster than 94.16% of C++ online submissions for Kth Largest Element in a Stream.
Memory Usage: 20 MB, less than 19.95% of C++ online submissions for Kth Largest Element in a Stream.
*/

class KthLargest {
private:
    int K;
    priority_queue <int, vector<int>, greater<int>> pq; //min heap
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto n:nums){
            pq.push(n);
            if(pq.size() > K) pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
