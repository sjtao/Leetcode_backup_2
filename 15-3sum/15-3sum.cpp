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
        unordered_set<int> seen;
        for(int i = k+1; i < nums.size(); i++){
            int c = - nums[i]-nums[k];
            if(seen.count(c)){
                ans.push_back({nums[k], c, nums[i]});
                while(i < nums.size()-1 && nums[i] == nums[i+1])
                    i++;
            }
            seen.insert(nums[i]);
        }
    }
};