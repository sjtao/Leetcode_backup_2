class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> day(n, 0);
        int cur; 
        int hot = t[n-1];
        for(int i = n-2; i >= 0; i--){
            cur = t[i];
            if(hot <= cur){
                hot = cur;
                continue;
            }
            
            int j = i+1;
            while(t[j] <= cur){
                j += day[j];
            }
            day[i] = j - i;
        }
        
        return day;
    }
};