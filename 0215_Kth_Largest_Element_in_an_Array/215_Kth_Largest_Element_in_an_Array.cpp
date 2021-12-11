/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10 MB, less than 56.81% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};

/**
Runtime: 8 ms, faster than 77.01% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.2 MB, less than 33.27% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Creates a max heap
        priority_queue <int> maxq(nums.begin(), nums.end());
        
        while(k > 1){
            maxq.pop();
            k--;
        }
        
        return maxq.top();
        
    }
};

/**
Runtime: 8 ms, faster than 77.01% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.3 MB, less than 17.98% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Creates a min heap
        priority_queue <int, vector<int>, greater<int>> minq;
        
        for(auto n:nums){
            minq.push(n);
            if(minq.size()>k)
                minq.pop();
        }
        
        return minq.top();
        
    }
};
