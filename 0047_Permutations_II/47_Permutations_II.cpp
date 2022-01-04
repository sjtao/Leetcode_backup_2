/**
Runtime: 188 ms, faster than 8.94% of C++ online submissions for Permutations II.
Memory Usage: 34 MB, less than 6.75% of C++ online submissions for Permutations II.
*/

class Solution {
public:
    int n;
    void permute(vector<int>& nums, vector<vector<int>>&group, int s){
        if(s == n-1){
            group.push_back(nums);
            return;
        }
        for(int i = s; i < n; i++){
            swap(nums[i], nums[s]);
            permute(nums, group, s+1);
            swap(nums[i], nums[s]);    
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> group;
        permute(nums, group, 0);
        
        //remove the repeat permutation
        set<vector<int>> st(group.begin(), group.end());
        group.clear();
        for(auto g:st){
            group.push_back(g);
        }
        
        return group;
        
    }
};
