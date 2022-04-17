class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left)/2;
            int hour = 0;
            for(int p : piles){
                hour += p / mid + (p % mid != 0);
            }
            
            if(hour <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};