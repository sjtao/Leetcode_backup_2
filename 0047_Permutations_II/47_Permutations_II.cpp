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

/**
Runtime: 4 ms, faster than 92.85% of C++ online submissions for Permutations II.
Memory Usage: 9 MB, less than 64.33% of C++ online submissions for Permutations II.
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
private:
    void permute(vector<int> nums, int start, vector<vector<int>>& perms) {
        int n = nums.size();
        if (start == n - 1) {
            perms.push_back(nums);
        } else {
            for (int i = start; i < n; i++) {
                if ((i == start) || (nums[i] != nums[start])) {
                    swap(nums[i], nums[start]);
                    permute(nums, start + 1, perms);
                }
            }
        }
    }
};
