class Solution {
public:
    unordered_map<int, int> mp = {{0, 0}, {1,1},{6,9},{8,8},{9,6}};
    bool confusingNumber(int n) {
        int k = n;
        int r = 0;
        while(k > 0){
            int m = k % 10;
            if(mp.find(m) == mp.end())
                return false;
            k /= 10;
            r = 10 * r +  mp[m];

        }
        return r != n;
    }
};