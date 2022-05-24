class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    ans[i] = j-i;
                    break;
                }
                else if(temperatures[j] == temperatures[i]){
                    ans[i] = ans[j] == 0 ? 0 : ans[j] + j-i;
                    break;
                }
            }
        }
        
        return ans;
    }
};