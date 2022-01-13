class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for(int n : nums)
            count[n]++;
        
        int pick = 0, delt = 0, prev = -1;
        for(int i = 0; i <10001; i++){
            if(count[i] != 0){
                int m = max(pick, delt);
                if(i-1 != prev)
                    pick = i * count[i] + m;
                else
                    pick = i * count[i] + delt;
                delt = m;
                prev = i;
            }  
        }
        
        return max(pick, delt);
    }
};