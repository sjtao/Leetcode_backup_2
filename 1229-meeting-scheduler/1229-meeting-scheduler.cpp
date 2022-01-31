class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n1 = slots1.size();
        int n2 = slots2.size();
        if(n1 < n2)
            return minAvailableDuration(slots2, slots1, duration);
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0;
        vector<int> ans;
        while(i < n1 && j < n2){
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if(start + duration <= end){
                ans.push_back(start);
                ans.push_back(start+duration);
                break;
            }
            
            if(end == slots1[i][1])
                i++;
            if(end == slots2[j][1])
                j++;
        }
        return ans;
    }
};