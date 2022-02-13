class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int n:nums){
            s.insert(n);
        }

        return !(s.size() == nums.size());
    }
};