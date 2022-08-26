class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        
        sort(nums.begin(), nums.end()); //O(nlogn)
        vector<vector<int>> ans;
        
        for(int i = 0; i < n && nums[i] <= 0; i++){
            if(i == 0 || nums[i-1] != nums[i])
                twosum(nums, i, ans);
        }
        //O(n^2)
        return ans;
    }
    
    void twosum(vector<int>& nums, int k, vector<vector<int>>& ans){
        int t = -nums[k];
        int l = k+1, r = nums.size()-1;
        while(l < r){
            int m = nums[l] + nums[r];
            if (m > t)
                r--;
            else if (m < t)
                l++;
            else{
                ans.push_back({nums[l++], -t, nums[r--]});
                while(l < r && nums[l] == nums[l-1]) l++;
                while(l < r && nums[r] == nums[r+1]) r--;
            }
        }
    }
};