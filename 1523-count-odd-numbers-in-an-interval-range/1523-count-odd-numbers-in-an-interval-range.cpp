class Solution {
public:
    int countOdds(int low, int high) {
        //starting from 1 # of odds
        int nh = high / 2 + high % 2;
        int nl = low == 0 ? 0 : (low-1) / 2 + (low-1) % 2;
        int ans = nh - nl;
        
        return ans;
        
    }
};