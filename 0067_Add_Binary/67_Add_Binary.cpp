//Runtime: 6 ms, faster than 17.81% of C++ online submissions for Add Binary.
//Memory Usage: 6.6 MB, less than 38.17% of C++ online submissions for Add Binary.

class Solution {
public:
    string addBinary(string a, string b) {
        
        int ai = a.length()-1;
        int bi = b.length()-1;
        
        vector<int> c;
        
        int cr = 0;
        int s  = 0;
        while(ai >= 0 && bi >= 0){
            s = a[ai] - '0' + b[bi] - '0' + cr;
            c.insert(c.begin(), s%2);
            cr = s / 2;
            ai --;
            bi --;
        }
        
        while(ai >= 0){
            s = a[ai] - '0' + cr;
            c.insert(c.begin(), s%2);
            cr = s / 2;
            ai --;
        }
        
        while(bi >= 0){
            s = b[bi] - '0' + cr;
            c.insert(c.begin(), s%2);
            cr = s / 2;
            bi --;
        }
        
        if(cr == 1) c.insert(c.begin(), 1);
        
        string ans = "\0";
        for(int i= 0; i < c.size(); i++){
            ans += (c[i] + '0');
        }
        
        return ans;
    }
};
