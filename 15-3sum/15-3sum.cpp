class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> com;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            int t = nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                int s = nums[l] + nums[r];
                if (s + t == 0){
                    com.insert({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                else if(s + t > 0)  r--;
                else l++;
            }
        }
        
        for(auto p : com)
            ans.push_back(p);
        
        return ans;
    }
};