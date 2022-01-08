class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //score = (a[i] + i + a[j] - j);
        //at i: maxscore[i] = (a[i] + i) + max(a[j] - j), j > i
        int n = values.size();
        int cur = values[n-1] - (n-1);
        int best = INT_MIN;
        for(int i = n-2; i >=0; i--){
            cur = max(values[i+1] - (i+1), cur);
            best = max(best, values[i] + i + cur);
        }
        return best;
    }
};