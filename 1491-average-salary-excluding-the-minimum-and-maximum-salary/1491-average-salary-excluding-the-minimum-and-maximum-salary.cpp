class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int mx = INT_MIN, mn = INT_MAX;
        int sum = 0;
        for(int s : salary){
            sum += s;
            mx = max(mx, s);
            mn = min(mn, s);
        }
        return 1.0 * (sum - mx - mn) / (n - 2);
    }
};