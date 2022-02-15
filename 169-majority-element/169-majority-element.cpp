class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = (int)floor(n/2);
        sort(nums.begin(), nums.end());
        int r = 1;
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                r++;
            }
            else{
                r = 1;
            }
            if(r > m){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};