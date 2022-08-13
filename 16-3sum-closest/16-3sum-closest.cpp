class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        //brutal force //TLE
        sort(nums.begin(), nums.end());
        int d = INT_MAX;
        for(int i = 0; i < n-2; i++){
            int l = i+1;
            int h = n-1;
            int m;
            while(l < h){
                int s = nums[i] + nums[l] + nums[h];
                if(s == target)
                    return s;
                else if(s > target)
                    h--;
                else
                    l++;
                if(abs(target - s) < abs(d))
                    d = target - s;
            }
        }
        return target - d;
    }
};