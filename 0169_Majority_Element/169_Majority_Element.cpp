/**
Runtime: 16 ms, faster than 81.38% of C++ online submissions for Majority Element.
Memory Usage: 19.6 MB, less than 86.94% of C++ online submissions for Majority Element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }
        int ans;
        for(auto n : mp){
            if (n.second > m){
                ans = n.first;
                break;
            }
        }
        return ans;
    }
};
