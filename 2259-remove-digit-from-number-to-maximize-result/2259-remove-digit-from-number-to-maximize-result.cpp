class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        //remove the leftmost digit if it's followed by a larger number
        //If we cannot find such case, we remove the last occurence of digit.
        int d = -1;
        for(int i = 0; i < n-1; i++){
            if(number[i] == digit){
                if(number[i+1] > digit)          
                    return number.erase(i, 1);
                d = i;
            }
        }
        if(number[n-1] == digit) d = n-1;
        return number.erase(d, 1);        
    }
};