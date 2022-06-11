class Solution {
public:
    int n;
    int binary(vector<int>& nums, int target, bool first){ 
        int l = 0, r = n-1;
        
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] > target)
                r = m - 1;
            else if(nums[m] < target)
                l = m + 1;
            else{
                if(first){
                    if(m == l || nums[m-1] != target)
                        return m;
                    r = m -1;
                }
                else{
                    if(m == r || nums[m+1] != target)
                        return m;
                    l = m + 1;
                }
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size();
        int first = binary(nums, target, true);
        int last  = binary(nums, target, false);
        return {first, last};
    }
};