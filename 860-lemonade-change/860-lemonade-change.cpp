class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        
        int five = 0, ten = 0, twenty = 0;
        for(int i = 0; i < bills.size(); ++i){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                ten++;
                five--;
                if(five < 0)
                    return false;
            }
            else if(bills[i] == 20){
                twenty++;
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(ten == 0 && five > 2){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};