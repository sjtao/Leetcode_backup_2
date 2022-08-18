class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n1 = slots1.size();
        int n2 = slots2.size();
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(slots1[i][0] > slots2[j][1])
                j++;
            else if(slots1[i][1] < slots2[j][0])
                i++;
            else{
                int ms = max(slots1[i][0], slots2[j][0]);
                int me = min(slots1[i][1], slots2[j][1]);
                if(me - ms >= duration)
                    return {ms, ms+duration};
                else{
                    if(me == slots1[i][1]) i++;
                    else j++;
                }
            }
        }
        
        return {};
        
    }
};