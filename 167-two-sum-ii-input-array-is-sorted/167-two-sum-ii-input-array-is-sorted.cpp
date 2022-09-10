class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int n = numbers.size();
        for(int i = 1; i < n+1; i++){
            int r = target - numbers[i-1];
            if(mp.count(r)){
                return {mp[r], i};
            }
            mp[numbers[i-1]] = i;
        }
        return {};
    }
};