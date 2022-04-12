class Solution {
public:
    int binary(vector<int>& nums, int target, int low, int high){
        int m;
        while(low <= high){
            m = low + (high-low)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                high = m-1;
            else
                low = m+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target ? 0 : -1;
        
        //find the minimum
        int l = 0, r = n-1, m;
        while(l < r){
            m = l + (r-l)/2;
            if(nums[m] < nums[r])
                r = m;
            else if(nums[m] > nums[r])
                l = m+1;
        }
        
        if (nums[l] == target)
            return l;
        
        if(l == 0)
            return binary(nums, target, 0, n-1);
        
        if(target < nums[0])
            return binary(nums, target, l, n-1);
        
        return binary(nums, target, 0, l);

    }
};