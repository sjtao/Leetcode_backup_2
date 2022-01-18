class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int n:nums)
            s.insert(n);
        
        int mx = 0;
        for(int n:nums){
            if(!s.count(n-1)){
                int cnt = 1;
                int cur = n+1;
                while(s.count(cur)){
                    cur++;
                    cnt++;
                }
                mx = max(cnt, mx);
            }
        }
        return mx;
    }
};