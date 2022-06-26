class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k == 1)
            return max(cardPoints[0], cardPoints[n-1]);
        
        vector<int> num(2*k);
        for(int i = 0; i < 2*k; i++){
            num[i] = cardPoints[(n-k+i)%n];
        }
        
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += num[i];
        }
        int mx = sum;
        for(int i = 0; i < k; i++){
            sum = sum-num[i]+num[k+i];
            mx = max(mx, sum);
        }
        
        return mx;
    }
};