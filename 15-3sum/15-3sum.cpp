class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void twosum(vector<int>& nums, int s){
        int k = - nums[s];
        int l = s+1, r = n-1;
        
        while(l < r){
            int m = nums[l] + nums[r];
            if(m > k)
                r--;
            else if (m < k)
                l++;
            else{
                ans.push_back({-k, nums[l++], nums[r--]});
                while(l < r && nums[l] == nums[l-1]) l++;
                while(l < r && nums[r] == nums[r+1]) r--;
            }
        }
    
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        if(n < 3) return ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                twosum(nums, i);
            }
        }
        
        return ans;
    }
};