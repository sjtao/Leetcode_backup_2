//Runtime: 16 ms, faster than 94.87% of C++ online submissions for Reverse String.
//Memory Usage: 23.1 MB, less than 76.01% of C++ online submissions for Reverse String.

class Solution {
public:
    
    void swap(char& x, char& y){
        char t = x;
        x = y;
        y = t;
    }
    void reverseString(vector<char>& s) {
        if(s.size() == 1) return;
        
        int i = 0;
        int r = s.size()-1;
        while(i < r){
            swap(s[i], s[r]);
            i++;
            r--;
        }
        
        return;
    }
};
