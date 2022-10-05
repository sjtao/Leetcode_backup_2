class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int m = 0;
        for(int c : candies)
            m = max(m, c);
        
        vector<bool> res(n, true);
        for(int i = 0; i < n; i++){
            if(candies[i] + extraCandies < m)
                res[i] = false;
        }
        
        return res;
    }
};