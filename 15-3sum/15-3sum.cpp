class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //set<vector<int>> com;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int t = nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                int s = nums[l] + nums[r];
                if (s + t == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    r--; l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
                else if(s + t > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        //for(auto p : com)
        //    ans.push_back(p);
        
        return ans;
    }
};