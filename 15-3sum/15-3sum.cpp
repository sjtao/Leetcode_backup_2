class Solution {
public:  
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n && nums[i] <= 0; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                int l = i+1; 
                int r = n-1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum > 0) r--;
                    else if(sum < 0) l++;
                    else{
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        
        return ans;
    }
};