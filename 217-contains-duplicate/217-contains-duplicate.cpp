class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int n : nums){
            if(s.count(n))
                return true;
            s.insert(n);
        }
        return false;
    }
};