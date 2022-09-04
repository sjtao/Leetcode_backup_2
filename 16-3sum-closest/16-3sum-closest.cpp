class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int d = INT_MAX;
        for(int i = 0; i < n && d != 0; i++){
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];
                int td = target - sum;
                if(abs(d) > abs(td))
                    d = td;
                if(td > 0) l++;
                else       r--;
            }
        }
        
        return target - d;
    }
};