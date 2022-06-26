class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k == 1)
            return max(cardPoints[0], cardPoints[n-1]);
        
        vector<int> forward(n+1, 0), backward(n+1,0);
        
        for(int i = 1; i < n+1; i++){
            forward[i] = forward[i-1] + cardPoints[i-1];
            backward[i] = backward[i-1] + cardPoints[n-i];
        }
        
        int sum = 0;
        for(int i = 0; i <= k; i++){
            sum = max(sum, forward[i]+backward[k-i]);
        }
        
        return sum;
    }
};