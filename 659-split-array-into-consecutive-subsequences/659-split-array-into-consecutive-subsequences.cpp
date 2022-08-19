class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp, sf;
        for(int a : nums)
            mp[a]++;
        
        for(int a : nums){
            if(mp[a] == 0)
                continue;
            if(sf[a-1] > 0){
                //add to existed sequence
                sf[a-1]--;
                sf[a]++;
            }
            //a, a+1, a+2
            else if(mp[a+1] > 0 && mp[a+2] > 0){
                mp[a+1]--;
                mp[a+2]--;
                sf[a+2]++;
            }
            else
                return false;
            mp[a]--;
        }
        return true;
    }
};