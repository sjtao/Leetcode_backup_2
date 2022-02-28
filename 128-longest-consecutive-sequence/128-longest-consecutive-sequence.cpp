class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        set<int> st;
        for(int a:nums)
            st.insert(a);
        
        int ans = 1;
        int cur = 1;
        int cur_a;
        for(int a : st){
            if(st.count(a-1) == 0){
                cur = 1;
                cur_a = a;
                while(st.count(cur_a+1) == 1){
                    cur_a++;
                    cur++;
                }
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};