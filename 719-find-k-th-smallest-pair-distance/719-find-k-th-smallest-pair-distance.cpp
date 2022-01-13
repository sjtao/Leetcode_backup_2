class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //O(nlogn)
        int l = 0, r = nums[n-1] - nums[0]; //smallest distance and largest distance
        int m;
        while(l < r){
            m = l + (r - l)/2;
            int c = 0;
            int j = 0;
            for(int i = 0; i < n; i++){
                while(j < n && nums[j]-nums[i] <= m){
                    j++;
                }
                c += j-i-1;
            }
            if(c >= k) r = m;
            else      l = m+1;
        }
        
        return l;
    }
};