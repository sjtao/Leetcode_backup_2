class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];});
        
        int n = boxTypes.size();
        int ans = 0;
        int left = truckSize;
        int i = 0;
        while(i < n && left > 0){
            int a = min(left, boxTypes[i][0]);
            left -= a;
            ans += a * boxTypes[i][1];
            i++;
        }
        
        return ans;
        
    }
};