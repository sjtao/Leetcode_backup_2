class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        int hottest = 0;
        for(int i = n-1; i >= 0; --i){
            if(temperatures[i] >= hottest){
                hottest = temperatures[i];
                continue;
            }
            int d = 1;
            while(temperatures[i+d] <= temperatures[i]){
                d += ans[i+d];
            }
            ans[i] = d;
        }
        return ans;
    }
};