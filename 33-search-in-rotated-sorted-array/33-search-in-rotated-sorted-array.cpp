class Solution {
public:
    int binary(vector<int>& nums, int target, int l, int r){
        if(l > r) return -1;
        int m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] < target){
                l = m+1;
            }
            else if(nums[m] > target){
                r = m-1;
            }
            else
                return m;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target ? 0 : -1;
        
        int l, r, m, k;
        
        if(nums[0] < nums[n-1])
            k = 0;
        else{
            l = 0;
            r = n-1;
            while(l <= r){
                m = l + (r - l)/2;
                if(nums[m] > nums[m+1]){
                    k = m+1;
                    break;
                }
                else{
                    if(nums[m] >= nums[l])
                        l = m+1;
                    else
                        r = m-1;
                }
            }
        }
        
        int ans = -1;
        if(k == 0)
            ans = binary(nums, target, 0, n-1);
        else
        {
            if(nums[0] <= target && nums[k-1] >= target)
                ans = binary(nums, target, 0, k-1);
            else if(nums[k] <= target && nums[n-1] >= target)
                ans = binary(nums, target, k, n-1);
        }
        
        return ans;
    }
};