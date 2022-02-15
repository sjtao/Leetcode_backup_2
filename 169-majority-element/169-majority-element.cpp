class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = (int)floor(n/2);
        unordered_map<int,int> mp;
        int ans;
        for(int a : nums){
            mp[a]++;
            if(mp[a] > m){
                ans = a;
                break;
            }
        }
        return ans;
    }
};