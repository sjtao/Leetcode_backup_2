class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brutal force
        int n = temperatures.size();
        vector<int> daily(n, 0);
        int hot = 0;
        for(int i = n-1; i >= 0; i--){
            int cur = temperatures[i];
            if(cur >= hot){
                hot = cur;
                continue;
            }
            
            int day = 1;
            while(temperatures[i + day] <= cur)
                day += daily[i + day];
            
            daily[i] = day;
        }
        
        return daily;
    }
};