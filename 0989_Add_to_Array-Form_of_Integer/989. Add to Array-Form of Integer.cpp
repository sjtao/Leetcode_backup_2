//Runtime: 28 ms, faster than 64.25% of C++ online submissions for Add to Array-Form of Integer.
//Memory Usage: 27.4 MB, less than 84.34% of C++ online submissions for Add to Array-Form of Integer.

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
 
        int i = num.size()-1;
        int carry = 0;
        int s;
        
        //add num and k 
        while(i >= 0){
            s = num[i] + k % 10 + carry;
            num[i] = s % 10;
            carry  = s / 10;
            k = k / 10;
            i--;
        }
        //for cases that k larger than num
        while(k > 0){
            s = k % 10 + carry;
            num.insert(num.begin(), s % 10);
            carry = s / 10;
            k = k / 10;
        }
        //insert 1 to the beginning if necessary
        if(carry){
            num.insert(num.begin(), carry);
        }
        
        return num;
    }
};
