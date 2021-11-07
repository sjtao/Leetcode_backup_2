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


//Runtime: 24 ms, faster than 85.09% of C++ online submissions for Add to Array-Form of Integer.
//Memory Usage: 29.4 MB, less than 5.66% of C++ online submissions for Add to Array-Form of Integer.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        
        //save k to a vector
        while(k > 0){
            ans.push_back(k % 10);
            k = k / 10;
        }
        reverse(ans.begin(), ans.end());
        
        int m = ans.size();
        int n = num.size();
        
        if(m > n){
            //k is longer then num
            int d = m - n;
            vector<int> temp(d, 0);
            temp.insert(temp.end(), num.begin(), num.end());
            num = temp;
        }
        else if(n > m){
            int d = n - m;
            vector<int> temp(d, 0);
            temp.insert(temp.end(), ans.begin(), ans.end());
            ans = temp;
        }
        
        int carry = 0;
        int s;
        for(int i = ans.size()-1; i >= 0; i--){
            s = ans[i] + num[i] + carry;
            ans[i] = s % 10;
            carry  = s / 10;
        }
        
        if(carry){
            ans.insert(ans.begin(), carry);
        }
        
        return ans;
    }
};

//Runtime: 20 ms, faster than 94.43% of C++ online submissions for Add to Array-Form of Integer.
//Memory Usage: 27.4 MB, less than 84.34% of C++ online submissions for Add to Array-Form of Integer.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size()-1;
        int carry = 0;
        int s;
        while(i >= 0 || k > 0){
            if(i >= 0){
                s = num[i] + k % 10 + carry;
                carry = s / 10;
                num[i] = s % 10;
            }
            else{
                s = k % 10 + carry;
                carry = s / 10;
                num.insert(num.begin(),s % 10);
            }
            
            k /= 10;
            i--; 
        }
        if(carry){
            num.insert(num.begin(),carry);
        }
        return num;
    }
};
