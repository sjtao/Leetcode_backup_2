
//brutal force cause time exceed limits
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        else{
            bool dup = 0;
            int i, j; 
            for(i = 0; i < n-1; i++){
                for(j = i + 1; j < n; j++){
                    if(nums[i] == nums[j]){
                        dup = 1;
                        break;
                    }
                }
            }
            return dup; 
        }
};

//Runtime: 39 ms, faster than 48.85% of C++ online submissions for Contains Duplicate.
//Memory Usage: 15.6 MB, less than 71.64% of C++ online submissions for Contains Duplicate.  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool dup = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                dup = 1;
                break;
            }
        }
        return dup;
    }
};

/**
Runtime: 65 ms, faster than 8.88% of C++ online submissions for Contains Duplicate.
Memory Usage: 20.2 MB, less than 60.20% of C++ online submissions for Contains Duplicate.
*/
class Solution {
public:
/*    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> np;
        for(auto n: nums){
            np[n]++;
            if(np[n]>1)
                return true;
        }
        return false;
    }
*/
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.find(i) != s.end())
                return true;
            s.insert(i);
        }
    return false;
}
};
