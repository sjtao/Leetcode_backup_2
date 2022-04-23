class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        int temp = temperatures[n-1];
        int tempid = n-1;
        for(int i = n-2; i >= 0; i--){
           if(temperatures[i] >= temp){
               temp = temperatures[i];
               tempid = i;
               ans[i] = 0;
           }
            else{
                int j = i+1;
                while(j <= tempid){
                    if(temperatures[i] < temperatures[j]){
                        ans[i] = j-i;
                        break;
                    }         
                    else if(temperatures[i] == temperatures[j]){
                        ans[i] = j-i + ans[j];
                        break;
                    }
                    j++;
                }
                
            }    
        }
        return ans;
    }
};