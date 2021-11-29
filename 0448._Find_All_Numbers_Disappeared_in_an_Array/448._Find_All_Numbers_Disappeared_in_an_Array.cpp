/**
Runtime: 96 ms, faster than 20.43% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 44.8 MB, less than 14.37% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> missed;
        for(int n: nums){
            mp[n]++;
        }
        int i = 1;
        while(i <= nums.size()){
            if(mp.find(i) == mp.end()){
                missed.push_back(i);
            }
            i++;
        }
        return missed;        
    }
};
