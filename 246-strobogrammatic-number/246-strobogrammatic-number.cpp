class Solution {
public:
    unordered_map<char,char> mp{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    bool isStrobogrammatic(string num) {
        int n = num.length();
        int l = 0, r = n-1;
        while(l <= r){
            if(mp.find(num[l]) == mp.end() || mp.find(num[r]) == mp.end() || mp[num[l]] != num[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};