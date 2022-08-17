class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        
        int len = 0;
        for(int n : nums){
            if(st.count(n-1)==0){
                int cur_n = n;
                int cur = 1;
                while(st.count(cur_n+1)){
                    cur_n++;
                    cur++;
                }
                len = max(len, cur);
            }
        }
        
        return len;
    }
};