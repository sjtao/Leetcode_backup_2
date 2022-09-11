class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
       
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        while(l < r){
            int m = l + (r-l)/2;
            int s = 0;
            for(int p : piles){
                s += (p / m + (p % m != 0));
            }
            if(s <= h){
                r = m;
            }
            else
                l = m+1;
        }
        return r;
    }
};