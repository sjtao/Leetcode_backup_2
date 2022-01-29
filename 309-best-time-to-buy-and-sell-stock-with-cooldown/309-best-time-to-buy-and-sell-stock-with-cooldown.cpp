class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, hold = INT_MIN, reset = 0;
        int presold;
        for(int p : prices){
            presold = sold;
            sold = hold + p;          //sell stock
            hold = max(hold, reset-p);//hold or buy a new one if no hold before
            reset = max(reset, presold);//no transactions 
        }
        return max(sold, reset);
        
    }
};