//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
//Memory Usage: 8.8 MB, less than 12.81% of C++ online submissions for Plus One.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 1){
            if (digits[0] < 9)
            {
                digits[0] += 1;
            }
            else
            {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        }
        else {
            int s = digits.size()-1;
            if(digits[digits.size()-1] < 9){
                digits[digits.size()-1] += 1;
            }
            else{
                while(s >= 0){
                    if(digits[s] == 9){
                        digits[s] = 0;
                        s--;
                    }
                    else{
                        digits[s] += 1;
                        break;
                    }
                    
                }
            }
            
            if (s == -1) digits.insert(digits.begin(), 1);  
        }
        
        return digits;
    }
    
};
