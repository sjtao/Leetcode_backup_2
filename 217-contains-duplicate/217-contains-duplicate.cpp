class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int n : nums)
            set.insert(n);
        return set.size() < nums.size();
    }
};