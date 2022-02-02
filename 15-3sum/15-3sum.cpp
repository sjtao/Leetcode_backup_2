class Solution {
public:
    int n;
    void twosum(vector<int>& nums, int i, vector<vector<int>>& ans){
        unordered_set<int> s;
        for(int j = i+1; j < n; j++){
            int t = -(nums[i] + nums[j]);
            if(s.count(t)){
                ans.push_back({nums[i], t, nums[j]});
                while(j < n-1 && nums[j] == nums[j+1]) j++;
            }
            s.insert(nums[j]);
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            twosum(nums, i, ans);
        }
        
        return ans;
    }
};