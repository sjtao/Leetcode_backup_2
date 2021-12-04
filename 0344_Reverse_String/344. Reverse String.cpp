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


//Runtime: 26 ms, faster than 35.92% of C++ online submissions for Reverse String.
//Memory Usage: 23.3 MB, less than 40.19% of C++ online submissions for Reverse String.
class Solution {
public:

    void reverseString(vector<char>& s) {
        if(s.size() > 1)
            reverse(s.begin(), s.end());
    }
};

/**
Runtime: 20 ms, faster than 79.70% of C++ online submissions for Reverse String.
Memory Usage: 23.2 MB, less than 40.05% of C++ online submissions for Reverse String.
*/
class Solution {
public:
    void reverseHelper(vector<char>& s, int left, int right){
        if(left >= right){
            return;
        }
        
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
        reverseHelper(s, left, right);
    }
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size()-1);
    }
};
