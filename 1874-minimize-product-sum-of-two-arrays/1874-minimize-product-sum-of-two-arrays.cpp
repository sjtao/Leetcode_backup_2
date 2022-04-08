class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>, greater<int>> q(nums1.begin(), nums1.end());
        priority_queue<int> p(nums2.begin(), nums2.end());
        
        int sum = 0;
        while(!q.empty()){
            sum += q.top() * p.top();
            q.pop();
            p.pop();
        }
        return sum;
    }
};