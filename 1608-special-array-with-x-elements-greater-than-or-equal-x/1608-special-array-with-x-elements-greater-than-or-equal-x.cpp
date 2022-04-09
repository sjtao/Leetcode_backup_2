class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] >= n) return n;
        
        int l = 1;
        int r = n-1;
        int m;
        while(l <= r){
            m = l + (r-l)/2;
            if(nums[m] >= n-m && nums[m-1] < n-m){               
                    return n-m;
            }
            else if(nums[m] >= n-m)
                r = m-1;
            else
                l = m+1;
        }
        return -1;
    }
};