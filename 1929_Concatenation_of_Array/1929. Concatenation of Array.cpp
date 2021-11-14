//Runtime: 12 ms, faster than 45.04% of C++ online submissions for Concatenation of Array.
//Memory Usage: 12.5 MB, less than 87.59% of C++ online submissions for Concatenation of Array.

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,0);
        
        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        
        return ans;
    }
};


//Runtime: 12 ms, faster than 45.04% of C++ online submissions for Concatenation of Array.
//Memory Usage: 12.7 MB, less than 63.05% of C++ online submissions for Concatenation of Array.
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> ans;
        ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};
