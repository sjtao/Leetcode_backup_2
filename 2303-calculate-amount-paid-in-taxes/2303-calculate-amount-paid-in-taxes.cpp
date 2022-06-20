class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if(income == 0) return 0.0;

        int i = 0;
        double pay = 0;
        int base = 0;
        while(income > base){
            pay += (min(income, brackets[i][0]) - base) * brackets[i][1] * 0.01;
            base = brackets[i][0];
            i++;
        }
        
        return pay;
    }
};