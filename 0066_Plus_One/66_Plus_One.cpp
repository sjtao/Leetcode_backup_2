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


/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 8.8 MB, less than 60.94% of C++ online submissions for Plus One.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1, res;
        for(int i = n-1; i >= 0; i--){
            res = digits[i] + carry;
            digits[i] = res % 10;
            carry = res / 10;
            if(carry == 0){
                break;
            }
        }
        if(carry){
            vector<int> ans;
            ans.push_back(carry);
            for(int d : digits){
                ans.push_back(d);
            }
            return ans;
        }

        return digits;
    }
};
