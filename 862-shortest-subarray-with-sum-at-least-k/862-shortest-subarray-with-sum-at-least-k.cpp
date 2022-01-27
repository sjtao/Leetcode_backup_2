class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> sum(n+1);
        stack<long> s;
        sum[0] = 0;
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i-1] + nums[i-1];
        }
        //smallest a-b for sum[a]-sum[b]>=k
        //monotonic queue
        int mn = n+1;
        deque<int> q;
        for(int i = 0; i <= n; ++i){
            while(!q.empty() && sum[i] <= sum[q.back()])
                q.pop_back();
            while(!q.empty() && sum[i] >= sum[q.front()] + k){
                mn = min(mn, i-q.front()); 
                q.pop_front();
            }
                
            q.push_back(i);
        }
        
        return mn == n+1 ? -1 : mn;
        
    }
};