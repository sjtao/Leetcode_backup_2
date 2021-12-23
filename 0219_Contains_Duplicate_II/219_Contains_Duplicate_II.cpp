/**
Runtime: 172 ms, faster than 48.92% of C++ online submissions for Contains Duplicate II.
Memory Usage: 77.2 MB, less than 28.00% of C++ online submissions for Contains Duplicate II.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) == mp.end())//not shown before
                mp[nums[i]] = i;
            else{//repeat value
                if(abs(i - mp[nums[i]]) <= k)
                    return true;
                else
                    mp[nums[i]] = i;
            }
        }
        return false;
    }
};

/**
Runtime: 164 ms, faster than 62.23% of C++ online submissions for Contains Duplicate II.
Memory Usage: 77.2 MB, less than 48.65% of C++ online submissions for Contains Duplicate II.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i]) && abs(i - mp[nums[i]]) <= k)
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
