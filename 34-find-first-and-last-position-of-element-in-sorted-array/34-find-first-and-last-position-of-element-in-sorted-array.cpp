class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n-1;
        int m;
        
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] > target)
                r = m-1;
            else if(nums[m] < target)
                l = m+1;
            else{
                //find target
                int first = m, last = m;
                while(first >= 0 && nums[first] == target) first--;
                while(last < n && nums[last] == target) last++;
                return {first+1, last-1};
            }
        }
        
        return {-1, -1};
    }
};