/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
Memory Usage: 7.1 MB, less than 61.31% of C++ online submissions for Subsets.
*/
class Solution {
public:
    int n;
    void sub(vector<int>& nums, vector<vector<int>>& group, vector<int>& uni,int k){
        if(k == n) return;
        
        for(int i = k; i < n; i++){
            uni.push_back(nums[i]);
            group.push_back(uni);
            sub(nums, group, uni, i+1);
            uni.pop_back();
        }
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> group;
        vector<int> uni;
        group.push_back(uni);
        sub(nums, group, uni, 0);
        return group;
    }
};
