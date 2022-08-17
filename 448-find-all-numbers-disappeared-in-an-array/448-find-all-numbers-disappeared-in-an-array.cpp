class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n+1, 0);
        vector<int> ans;
        //[1, n]
        for(int i : nums)
            val[i]++;
        for(int i = 1; i <= n; i++){
            if(val[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};