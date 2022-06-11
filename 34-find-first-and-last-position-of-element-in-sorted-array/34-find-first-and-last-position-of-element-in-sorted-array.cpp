class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = -1, ed = -1;
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] > target)
                r = m - 1;
            else if(nums[m] < target)
                l = m + 1;
            else{
                ed = m;
                st = m;
                while(ed < n && nums[ed] == target)
                    ed ++;
                while(st >= 0 && nums[st] == target)
                    st --;
                return {st+1, ed-1};
            }
        }
        return {st, ed};
    }
};